from typing import BinaryIO
import argparse
import socket
import time
import struct

RUDP_HEADER_FORMAT = "IB"  # Unsigned Int for sequence number, Byte for packet type (0: Data, 1: ACK, 2: NACK)
HEADER_SIZE = struct.calcsize(RUDP_HEADER_FORMAT)

# Constants for RUDP
TIMEOUT = 0.06  # Timeout in seconds
SERVERTIMEOUT = 0.06
MAX_PACKET_SIZE = 256  # Max size of each data packet
MAX_PAYLOAD_SIZE = MAX_PACKET_SIZE - HEADER_SIZE
WINDOW_SIZE = 15  # Number of packets in the window


def make_packet(seq_num, packet_type, payload=b''):
    seq_num = seq_num % WINDOW_SIZE
    header = struct.pack(RUDP_HEADER_FORMAT, seq_num, packet_type)
    return header + payload


def parse_packet(packet):
    header = packet[:HEADER_SIZE]
    payload = packet[HEADER_SIZE:]
    seq_num, packet_type = struct.unpack(RUDP_HEADER_FORMAT, header)
    return seq_num, packet_type, payload


def gbn_client(host: str, port: int, fp: BinaryIO) -> None:
    if not host:
        host = 'localhost'

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print("Client started!")
    base = 0
    next_seq_num = 0
    packets = []

    def send_window():
        nonlocal next_seq_num
        while next_seq_num < base + WINDOW_SIZE:
            chunk = fp.read(MAX_PAYLOAD_SIZE)
            if not chunk:
                break
            packet = make_packet(next_seq_num, 0, chunk)  # 0 for data packet
            packets.append(packet)
            client_socket.sendto(packet, (host, port))
            print(f"Sent packet: Seq Num={next_seq_num}, Size={len(chunk)} bytes")
            next_seq_num += 1
        if base == next_seq_num - WINDOW_SIZE:
            client_socket.settimeout(TIMEOUT)

    send_window()

    while base < next_seq_num:
        try:
            ack_packet, _ = client_socket.recvfrom(MAX_PACKET_SIZE)
            ack_seq_num, ack_type = struct.unpack(RUDP_HEADER_FORMAT, ack_packet[:HEADER_SIZE])

            if ack_seq_num >= base and ack_type == 1:  # ACK packet
                base = ack_seq_num + 1
                send_window()
            elif ack_type == 2:  # NACK packet
                for i in range(ack_seq_num, next_seq_num):
                    client_socket.sendto(packets[i - base], (host, port))
                    print(f"Resent packet: Seq Num={i}, Size={len(packets[i]) - HEADER_SIZE} bytes")

        except socket.timeout:
            print("Timeout, resending window")
            for i in range(base, next_seq_num):
                client_socket.sendto(packets[i], (host, port))
                print(f"Resent packet: Seq Num={i}, Size={len(packets[i]) - HEADER_SIZE} bytes")
            if base < next_seq_num:
                client_socket.settimeout(TIMEOUT)

    eof_packet = make_packet(next_seq_num, 3)
    client_socket.sendto(eof_packet, (host, port))
    client_socket.close()
    print("Client connection closed.")


def gbn_server(iface: str, port: int, fp: BinaryIO) -> None:
    if not iface:
        iface = 'localhost'
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind((iface, port))
    print(f"Server started on {iface}:{port}")
    server_socket.settimeout(SERVERTIMEOUT)

    expected_seq_num = 0
    last_ack_packet = None

    while True:
        try:
            packet, client_addr = server_socket.recvfrom(MAX_PACKET_SIZE)
            seq_num, packet_type, data = parse_packet(packet)
            packet_type_str = {0: 'DATA', 1: 'ACK', 2: 'NACK', 3: 'EOF'}.get(packet_type, 'Unknown')
            print(f"Received packet: Seq Num={seq_num}, Type={packet_type_str}, Size={len(data)} bytes")

            if packet_type == 3:
                print("EOF received. Closing connection.")
                break

            if packet_type == 0 and seq_num == expected_seq_num:
                fp.write(data)
                fp.flush()
                ack_packet = make_packet(seq_num, 1)
                server_socket.sendto(ack_packet, client_addr)
                last_ack_packet = ack_packet
                expected_seq_num += 1

            elif packet_type == 0 and seq_num != expected_seq_num:
                print('Client out of order, sending NACK packet.')
                nack_packet = make_packet(expected_seq_num, 2)  # 2 for NACK
                server_socket.sendto(nack_packet, client_addr)

        except socket.timeout:
            if last_ack_packet is not None:
                server_socket.sendto(last_ack_packet, client_addr)
                print("Timeout occurred, resending the last ACK packet")

    fp.close()
    server_socket.close()
    print("Server connection closed.")
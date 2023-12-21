import argparse
import socket
import time
import struct

# Define the RUDP header format
RUDP_HEADER_FORMAT = "IB"  # Unsigned Int for sequence number, Byte for packet type (0: Data, 1: ACK, 2: NACK)
HEADER_SIZE = struct.calcsize(RUDP_HEADER_FORMAT)

# Constants for RUDP
TIMEOUT = 0.06  # Timeout in seconds
MAX_PACKET_SIZE = 256  # Max size of each data packet
MAX_PAYLOAD_SIZE = MAX_PACKET_SIZE - HEADER_SIZE
print(f"Maximum Payload Size: {MAX_PAYLOAD_SIZE} bytes")


def make_packet(seq_num, packet_type, payload=b''):
    # packet type would be nack or ack
    header = struct.pack(RUDP_HEADER_FORMAT, seq_num, packet_type)
    return header + payload


def parse_packet(packet):
    # slice up packet before and after header_size index.
    header = packet[:HEADER_SIZE]
    payload = packet[HEADER_SIZE:]
    # header is consistent binary so it is unpacked whereas the payload isn't, so we leave it to higher level machine
    # functions
    seq_num, packet_type = struct.unpack(RUDP_HEADER_FORMAT, header)
    return seq_num, packet_type, payload


def stopandwait_client(host, port, fp):
    packet_number = 0
    # create udp socket, checksum logic is also encapsulated in this.
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # the timeout before a packet must be resent
    client_socket.settimeout(TIMEOUT)
    seq_num = 0  # Start the client with sequence number 0
    start_time = time.time()
    max_duration = 30000  # Session timer, i.e., when we should give up

    print(f"Client started, sending to {host}:{port}")

    while True:
        elapsed_time = time.time() - start_time  # Calculate elapsed time
        if elapsed_time > max_duration:
            print(f"Session timeout exceeded ({max_duration} seconds). Terminating.")
            break

        # Read data chunk based on calculated payload size, accounting for the header space
        chunk = fp.read(MAX_PAYLOAD_SIZE)
        if not chunk:
            print("End of file reached, stopping client.")
            break

        packet = make_packet(seq_num, 0, chunk)  # 0 for data packet
        print(f"Sending packet with seq_num: {seq_num}")

        while True:
            try:
                client_socket.sendto(packet, (host, port))
                # use netsters version of recv, this should handle checksums by itself.
                ack_packet, _ = client_socket.recvfrom(MAX_PACKET_SIZE)
                # again convert from binary
                ack_seq, received_packet_type = struct.unpack(RUDP_HEADER_FORMAT, ack_packet[:HEADER_SIZE])

                if ack_seq == seq_num:
                    if received_packet_type == 1:  # ACK
                        print(f"CLIENT: ACK received for seq_num: {seq_num}")
                        packet_number += 1
                        break
                    elif received_packet_type == 2:  # NACK
                        print(f"CLIENT: NACK received, resending packet with seq_num: {seq_num}")
                        continue

            # if an ack is dropped this should be done.
            except socket.timeout:
                print(f"Timeout, resending packet with seq_num: {seq_num}, packet number: {packet_number}")
                continue

        seq_num = 1 - seq_num  # Flip sequence number for the next packet

    client_socket.close()
    print("Client connection closed.")


def stopandwait_server(iface, port, fp):
    if iface is None:
        iface = '0.0.0.0'

    # Inherent timeout for ACK resending
    ack_timeout = 0.03  # 3 milliseconds

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind((iface, port))
    expected_seq_num = 0
    last_ack_time = None
    last_ack_packet = None

    print(f"Server running on {iface}:{port}")

    while True:
        # set the timeout block
        server_socket.settimeout(ack_timeout)
        try:
            packet, client_addr = server_socket.recvfrom(MAX_PACKET_SIZE)
            seq_num, packet_type, data = parse_packet(packet)
            # check elapsed time between acks
            last_ack_time = time.time()

            if packet_type == 0:  # Data packet
                if seq_num == expected_seq_num:
                    print(f"SERVER: correctly sequenced data packet received, sending ACK")
                    fp.write(data)
                    fp.flush()
                    ack_packet = make_packet(seq_num, 1)  # ACK
                    server_socket.sendto(ack_packet, client_addr)
                    last_ack_packet = ack_packet
                    expected_seq_num = 1 - expected_seq_num

                else:
                    print(f"SERVER: packet out of sequence, sending NACK")
                    nack_packet = make_packet(seq_num, 2)  # NACK
                    server_socket.sendto(nack_packet, client_addr)

        except socket.timeout:
            # Resend the last ACK if the timeout occurs and we had previously received a history of packets
            if last_ack_time is not None and last_ack_packet is not None and (time.time() - last_ack_time) >= ack_timeout:
                print(f"Timeout, resending ACK for seq_num: {1 - expected_seq_num}")
                server_socket.sendto(last_ack_packet, client_addr)

    server_socket.close()
    print("Server connection closed.")

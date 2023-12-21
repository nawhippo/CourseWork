#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#define ENDTRANS "END"
#define MAX_MESSAGE_SIZE 256

void file_server(char* iface, long port, int use_udp, FILE* fp) {
    //socket declarations
    int sockfd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);

    //Determine protocol: udp/tcp
    if (use_udp)
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    else
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //initialize server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = port;
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to specified port and address
    bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address));

    //tcp connection listenin
    if (!use_udp)
        listen(sockfd, 1);

    //accept conns
    int new_socket = sockfd;
    if (!use_udp)
        new_socket = accept(sockfd, (struct sockaddr*)&client_address,  &client_len);

    char buffer[MAX_MESSAGE_SIZE];
    ssize_t bytes_received;

    //loop to receive data from client and write to file
    if (use_udp) {
        while (1) {
            bytes_received = recvfrom(sockfd, buffer, MAX_MESSAGE_SIZE, 0, (struct sockaddr*)&client_address, &client_len);
            if (bytes_received > 0) {
                // Check for end-of-transmission signal
                if (strncmp(buffer, ENDTRANS, strlen(ENDTRANS)) == 0) {
                    break;
                }
                fwrite(buffer, 1, bytes_received, fp);
            }
        }
    } else {
        while ((bytes_received = recv(new_socket, buffer, MAX_MESSAGE_SIZE, 0)) > 0) {
            fwrite(buffer, 1, bytes_received, fp);
        }
    }

    //close file and respective sockets
    fclose(fp);

    close(new_socket);
    close(sockfd);

    exit(0);
}

void file_client(char* host, long port, int use_udp, FILE* fp) {
    //socket and descriptor declarations
    int sockfd;
    struct sockaddr_in server_address;

    //create socket based on protocol: UDP or TCP
    if (use_udp)
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    else
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //initialize server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = port;
    inet_pton(AF_INET, host, &server_address.sin_addr);

    //establish connection with the server for TCP
    if (!use_udp)
        connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address));

    char buffer[MAX_MESSAGE_SIZE];
    ssize_t bytes_read;

    //loop to read data from file and send to server
    if (use_udp) {
        while ((bytes_read = fread(buffer, 1, MAX_MESSAGE_SIZE, fp)) > 0) {
            sendto(sockfd, buffer, bytes_read, 0, (struct sockaddr*)&server_address, sizeof(server_address));
            usleep(1000); // sleep for 1 millisecond
        }
        // Send the end-of-transmission signal
        sendto(sockfd, ENDTRANS, strlen(ENDTRANS), 0, (struct sockaddr*)&server_address, sizeof(server_address));
    } else {
        while ((bytes_read = fread(buffer, 1, MAX_MESSAGE_SIZE, fp)) > 0) {
            send(sockfd, buffer, bytes_read, 0);
        }
    }

    //close the file and socket
    fclose(fp);
    close(sockfd); 

    exit(0);
}
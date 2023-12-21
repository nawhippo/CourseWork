#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 256

void chat_server(char *iface, long port, int use_udp) { 
    int sockfd, connfd = 0;
    int connection_count = 0;
    struct sockaddr_in server, client;
    char buffer[MAX];
    int write_result;
    socklen_t len = sizeof(client);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    //ipv4
    hints.ai_family = AF_INET;
    char port_str[6];
    snprintf(port_str, sizeof(port_str), "%ld", port);
    //set according to server type
    hints.ai_socktype = use_udp ? SOCK_DGRAM : SOCK_STREAM;

    if (getaddrinfo(iface, port_str, &hints, &res) != 0) {
        perror("getaddrinfo failed");
        exit(1);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(iface);

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (!use_udp && listen(sockfd, 10) < 0) {
        perror("listen failed");
        exit(1);
    }

    if (use_udp) {
        //udp loop
        while (1) {
            int n;
            n = recvfrom(sockfd, buffer, MAX - 1, 0, (struct sockaddr *)&client, &len);

            if (n <= 0) {
                break;
            }

            buffer[n] = '\0';
            printf("got message from ('%s', %d)\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

            if (strcmp(buffer, "hello\n") == 0) {
                sendto(sockfd, "world\n", 7, 0, (struct sockaddr *)&client, len);
            } else if (strcmp(buffer, "goodbye\n") == 0) {
                sendto(sockfd, "farewell\n", 9, 0, (struct sockaddr *)&client, len);
            } else if (strcmp(buffer, "exit\n") == 0) {
                sendto(sockfd, "ok\n", 3, 0, (struct sockaddr *)&client, len);
                close(sockfd);
                exit(0);
            } else {
                sendto(sockfd, buffer, n, 0, (struct sockaddr *)&client, len);
            }
        }
    } else {
        // TCP Loop
        while (1) {
            int n;
            connfd = accept(sockfd, (struct sockaddr *)&client, &len);
            if (connfd < 0) {
                perror("accept failed");
                exit(1);
            }

            printf("connection %d from ('%s', %d)\n", connection_count, inet_ntoa(client.sin_addr), ntohs(client.sin_port));
            connection_count++;

            while (1) {
                n = read(connfd, buffer, MAX - 1);

                if (n <= 0) {
                    close(connfd);
                    break;
                }

                buffer[n] = '\0';
                printf("got message from ('%s', %d)\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

                if (strcmp(buffer, "hello\n") == 0) {
                    write_result = write(connfd, "world\n", 6);
                } else if (strcmp(buffer, "goodbye\n") == 0) {
                    write_result = write(connfd, "farewell\n", 9);
                    close(connfd);
                    break;
                } else if (strcmp(buffer, "exit\n") == 0) {
                    write_result = write(connfd, "ok\n", 3);
                    close(connfd);
                    close(sockfd);
                    exit(0);
                } else {
                    write_result = write(connfd, buffer, n);
                }

                if (write_result < 0) {
                    perror("write failed");
                }
            }
        }
    }

    freeaddrinfo(res);
}

void chat_client(char *host, long port, int use_udp) {
   int sockfd;
    struct sockaddr_in server;
    struct addrinfo hints, *res;
    char buffer[MAX];
    int write_result;
    char *fgets_result;
    socklen_t len = sizeof(server);

    //setup hints structure and call getaddrinfo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = use_udp ? SOCK_DGRAM : SOCK_STREAM;
    if (getaddrinfo(host, NULL, &hints, &res) != 0) {
        perror("getaddrinfo failed");
        exit(1);
    }

    //create socket
    sockfd = socket(res->ai_family, res->ai_socktype, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    //setup server details based on getaddrinfo results
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = ((struct sockaddr_in*)res->ai_addr)->sin_addr;

    //free the address info
    freeaddrinfo(res);

    if (!use_udp) {
        if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
            perror("connect failed");
            exit(1);
        }
    }

    while (1) {
        printf("Enter message: ");
        fgets_result = fgets(buffer, MAX, stdin);
        if (fgets_result != NULL) {
             size_t msg_len = strlen(buffer);
            if (buffer[msg_len - 1] != '\n') {
            buffer[msg_len] = '\n';
            buffer[msg_len + 1] = '\0';
            msg_len++;
        }
            int n;
            if (use_udp) {
                if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server, len) == -1) {
                    perror("sendto failed");
                    continue;
                }
                n = recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr *)&server, &len);
            } else {
                write_result = write(sockfd, buffer, strlen(buffer));
                if (write_result == -1) {
                    perror("write failed");
                    continue;
                }
                n = read(sockfd, buffer, MAX);
            }
            if (n == -1) {
                perror("read failed");
                continue;
            }
            buffer[n] = '\0';
            printf("%s\n", buffer);

            //terminate
            if (strcmp(buffer, "farewell\n") == 0 || strcmp(buffer, "ok\n") == 0) {
                close(sockfd);
                exit(0);
            }
        } else {
            perror("fgets failed");
        }
    }
}
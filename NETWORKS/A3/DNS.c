#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }
    //initialize hints struct
    //aslo declare the start of the results list.
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    //choice of socket family doesn't matter
    hints.ai_family = PF_UNSPEC;
    //tcp socket
    hints.ai_socktype = SOCK_STREAM;
    //any protocol, System will set it.
    hints.ai_protocol = 0;
    //perform dns query
    if(getaddrinfo(argv[1], argv[2],&hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }


    //iterate through the result list, assigning the values
    for(struct addrinfo *p = res; p != NULL; p = p->ai_next) {
        void *addr;
        //str for converted ips
        char ipstr[INET6_ADDRSTRLEN];
        //type of ip itself.
        const char *ipver;
        //if its ipv4
        if (p->ai_family ==  AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else {
        //ipv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }
        //convert this to a human readible string.
        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        printf("%s %s\n", ipver, ipstr);
    }

    //clean up add info
    freeaddrinfo(res);

    return 0;
}

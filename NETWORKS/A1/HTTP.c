#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

//import function from http file
extern void send_http(char *host, char *message, char *resp, int len);
int main(int argc, char *argv[]) {
    //validate arg number
    if (argc != 4) {
        printf("Incorrect number of arguments");
        return 1;
    }

    char *host = argv[1];
    char *verb = argv[2];
    char *path = argv[3];

    //check the verb. Get or post. 
    if (strcmp(verb,"GET") != 0 && strcmp(verb, "POST")!= 0) {
        printf("invalid verb. You can only make get and post requests\n");
        return 1;
    }

    //prepare and format the req bytes as per the assignment
    char request[4096];

    snprintf(request,sizeof(request), "%s %s HTTP/1.0\r\nHost: %s\r\n\r\n", verb, path, host);

    //make the request
    char response[4096];
    send_http(host,  request, response, sizeof(response));

    //prrint the response
    printf("%s\n", response);

    return 0;
}
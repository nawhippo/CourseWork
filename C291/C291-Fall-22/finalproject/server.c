#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

char *decrypt(char *cipher_text, int key){
    char ch;
    for (int i = 0; cipher_text[i] != '\0'; ++i) {
    ch = cipher_text[i];
    if (isalnum(ch)) {
      if (islower(ch)) {
        ch = (ch - 'a' - key + 26) % 26 + 'a';
      }
      if (isupper(ch)) {
        ch = (ch - 'A' - key + 26) % 26 + 'A';
      }
      if (isdigit(ch)) {
        ch = (ch - '0' - key + 10) % 10 + '0';
      }
    }
    cipher_text[i] = ch;
  }
  //text should now be deciphered. 
  return cipher_text;
}

int toInt(char *key){
    int i = atoi(key);
    return i;
}

char *split(char cipher_text[]){
    // 1. Split the key and encrypted text
    char *key = strtok(cipher_text,":");
    //message is after the colon
    char *message  = strtok(NULL,":");
    // 2. Convert the key to int
    int n = toInt(key);
    // 3. Call the decrypt function with encrypted text and key as an argument
    char * decrypted_message;
    decrypted_message = decrypt(message, n);
    return decrypted_message;
    // 4. Return the plain text
}

void main(){
    // 1. Create Socket
    int socket_desc = socket(AF_INET, SOCK_DGRAM, 0); 
    // 2. Initialize the struct variables
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    // 3. Bind
    bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
    // 4. Create client_addr struct and get the length of struct client_addr
    struct sockaddr_in client_addr; 
    int client_struct_length = sizeof(client_addr);
    
    //initialize encrypted_text to receive from client 
    char encrypted_text[MESS_LEN];
    // 5. Wait for the Client to send the message and receive it using recfrom() method, and return type is int (Length of the message)
    int n = recvfrom(socket_desc, encrypted_text, sizeof(encrypted_text), 0, (struct sockaddr*) &client_addr, &client_struct_length); 
    // 6. Call the split function and inside a split function, call the decrypt function to get plain text
    char * deciphered_text = split(encrypted_text);
    // 7. Print the plain text
    printf("Data Received: %s", deciphered_text);
}



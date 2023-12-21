#include <stdio.h>
#include <sys/socket.h> //socket apis
#include <netinet/in.h> //stores address information
#include <stdlib.h>
#include <string.h> //for manipulating strings for encryption
#include "functions.h"

    //FUNCTIONS for encryption
int get_key_len(int key){
	    int key_len = 0;
	    // Return the number of digits of the key
	    while(key!=0){
	        key=key/10;
	        key_len++;
	            }
	    return key_len;
	}
	
	//converts the key to a string
char *toString(int key){
	 // 1. Get the number of digits of the key 
	int digitnum = get_key_len(key);
    // 2. Convert into a character pointer and return it.
    char * result = malloc(sizeof(char) * digitnum + 1);
    sprintf(result,"%d",key);
    return result;
	}
	
char *encrypt(char plain_text[MESS_LEN], int key){ 
    // 1. Convert the plain_text to encrypt_text using key 
    for(int i = 0; (i < MESS_LEN && plain_text[i] != '\0'); i++){
        //leave spaces alone
        if(plain_text[i] == ' '){
           plain_text[i] = ' ';
        } else {
        plain_text[i] = plain_text[i] + key;
    }
    }
    // 2. Convert the key (int) to a Character pointer using the toString()    
    char* keystring = toString(key);
    //formatted key:message
    // 3. Concat key:encrypt_text 
    char* keystringcolon = strcat(keystring,":");
    char* enc_message = strcat(keystringcolon,plain_text);
    // 4. Return the key:encrypt_text to main() method     
    return enc_message;
} 

void main(){
    //initialize socket
    int sockdesc=socket(PF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT); //port specified 
    server_addr.sin_addr.s_addr=INADDR_ANY;

    int connectionStatus = connect(sockdesc, (struct sockaddr*)&server_addr,sizeof(server_addr));
    if (connectionStatus == -1) {
    printf("Error: Connection failed\n");
} else {
    //initialize the message, take user input and encrypt it.
    char message[MESS_LEN];
    int key = 0; 

    printf("Please enter a message to encrypt: ");
    fgets(message,MESS_LEN,stdin);

    printf("\nPlease enter the encryption key: ");
    scanf("%d", &key);

    //encrypts message and sends it.
    char * encrypted_text = encrypt(message, key);
    sendto(sockdesc, encrypted_text, strlen(encrypted_text), 0, (struct sockaddr*) &server_addr, sizeof(server_addr));
    printf("\nData Sent: %s", encrypted_text);
}
}












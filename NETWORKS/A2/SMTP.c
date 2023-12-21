#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//to read file..
char* read(const char* filename);
int connect_smtp(const char* host, int port);
void send_smtp(int sock, const char* msg, char* resp, size_t len);

/*
  Use the provided 'connect_smtp' and 'send_smtp' functions
  to connect to the "lunar.open.sice.indian.edu" smtp relay
  and send the commands to write emails as described in the
  assignment wiki.
 */
int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Invalid arguments - %s <email-to> <email-filepath>", argv[0]);
    return -1;
  }
  char* rcpt = argv[1];
  char* filepath = argv[2];
  char response[4096];
  
  /* 
     STUDENT CODE HERE
   */
int socket = connect_smtp("lunar.open.sice.indiana.edu", 25);
if(socket < 0){
	printf("failed to cobnnect to SMTP server. \n");
	return -1;
}

//greet server 

send_smtp(socket, "HELO localhost\r\n", response, sizeof( response));
printf("%s\n", response);

//signify sender
char sender_comm[256];
snprintf(sender_comm, sizeof(sender_comm), "MAIL FROM:<%s>\r\n", rcpt);
send_smtp(socket, sender_comm, response, sizeof(response));
printf("%s\n", response);


char rcptcomm[256];
snprintf(rcptcomm, sizeof(rcptcomm),"RCPT TO:<%s>\r\n", rcpt);
send_smtp(socket, rcptcomm, response, sizeof(response));
printf("%s\n", response);


//read from file
char* email = read(filepath);
if(email == NULL){
	printf("Could not read email from file.. \n");
	return 1;
}

//declare message
send_smtp(socket,  "DATA\r\n", response,  sizeof(response));

printf("%s\n", response);

//email content of file + extra space for termination sequence
char* term_email = malloc(strlen(email)+4);

//add termination to end of email to server
sprintf(term_email, "%s\r\n.\r\n", email);
send_smtp(socket,  term_email, response, sizeof(response));

//if not successful ie 250
if (strncmp(response, "250", 3) != 0) {
    printf("sending email failed:%s\n",  response);
    return -1;
}
printf("%s\n", response);

//quit, close SMTP Session
send_smtp(socket, "QUIT\r\n", response, sizeof(response));


free(email);

return 0;
}



char* read(const char* filename) {
//BINARY MODE
FILE* file = fopen(filename,   "rb");
if (file == NULL) {
	return NULL;
}

if (fseek(file, 0, SEEK_END) != 0) {
	fclose(file);
	return NULL;
}
long len = ftell(file);

//If there is an error
if (len == -1) {
	fclose(file);
	return NULL;
}
//check for maximum allowed email size 4096
if (len > 4096) {
	fclose(file);
        return NULL;
}
if (fseek(file, 0, SEEK_SET) != 0) {
	fclose(file);
        return NULL;
}
char *buffer = (char*) malloc(len+1);
if (buffer == NULL) {
        fclose(file);
        return NULL;
}
//nul terminate to end file.
size_t readsz = fread(buffer, 1,  len, file);
buffer[len] =  '\0'; 
if (readsz != (size_t) len) {
	fclose(file);
	free(buffer);
	return NULL;
}
fclose(file);
return buffer;
}

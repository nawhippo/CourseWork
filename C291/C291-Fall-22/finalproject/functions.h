extern int MESS_LEN 500;
extern int PORT 8000;

//function prototypes
int get_key_len(int key);
char *toString(int key);
char *encrypt(char plain_text[MESS_LEN], int key);
char *split(char cipher_text[MESS_LEN]);
char *decrypt(char *cipher_text, int key);
int toInt(char *key);


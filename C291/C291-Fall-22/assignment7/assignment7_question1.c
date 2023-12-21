
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHARLENGTH 50
char ** myTokenizer(char * str, const char *delim);

int main (void){
char input[MAXCHARLENGTH];
char delimiter[MAXCHARLENGTH];


printf("Input the string: ");
fgets(input,50,stdin);

printf("Input the delimiter: ");
fgets(delimiter,50,stdin);

int count = 0;
int count1 = 0;
puts("Wonderful");
 
    //resize string.
    for(int i = 0; (isalnum(input) | ispunct(input[i]) | isblank(input) | (input[i]=='\0')); i++){
        count++;
    }
    
    
    
    for(int i = 0; (isalnum(delimiter[i]) | ispunct(delimiter[i]) | isblank(delimiter[i]) | (delimiter[i]=='\0')); i++){
        count1++;
    }
    
    count++;
    count1++;
    
    char input1[count];
    char delimiter1[count1];
    strcpy(input1,input);
    strcpy(delimiter1,delimiter);


char** results = myTokenizer(input1, delimiter1);

puts("printing results");
for(int i = 0; results[i] != "end"; i++){
    printf("%s\n",results[i]);
}

}


char ** myTokenizer(char * str, const char *delim){
    int success = 0;
    int r = 0;
    char **mytokens;
    mytokens = (char**)malloc(sizeof(char) * 500);
    char token[strlen(str)];
   
    for(int i = 0, r = 0; str[i] != '\n'; i++){
        if(str[i] == delim[0]){
            for(int r = i, p = 0; str[r] == delim[p]; p++){
                if (p == (strlen(delim)-2)){
                    puts("delim detected");
                    for(int p = 0; str[p] != delim[0]; p++){
                        token[p]=str[p];
                    }
                    mytokens[r] = token;
                    i+=strlen(delim);
                    r++;
                }
            }
        }
        mytokens[r] = token;
        }
        mytokens[r] = "end";
        return mytokens;
}
        
        
        
        
        
        












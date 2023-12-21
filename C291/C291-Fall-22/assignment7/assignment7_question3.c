char * replaceAll(const char * string, char * target, char * replacement);
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHARLENGTH 50
int main()
{
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    int index;
    int startindex;
    char str[MAXCHARLENGTH];
    char search[MAXCHARLENGTH];
    char replacement[MAXCHARLENGTH];
    printf("Please enter a String: ");
    fgets(str, 50, stdin);
    printf("Please enter a target: ");
    fgets(search, 50, stdin);
    printf("Please enter a replacement: ");
    fgets(replacement, 50, stdin);
    puts("Wonderful");
 
    //resize string.
    for(int i = 0; (isalnum(str[i]) | ispunct(str[i]) | isblank(str[i]) | (str[i]=='\0')); i++){
        count++;
    }
    
    count++;
    
    for(int i = 0; (isalnum(search[i]) | ispunct(search[i]) | isblank(search[i]) | (search[i]=='\0')); i++){
        count1++;
    }
    count1++;
    
     for(int i = 0; (isalnum(search[i]) | ispunct(search[i]) | isblank(search[i]) | (search[i]=='\0')); i++){
        count2++;
    }
    count2++;
    
    
    const char str1[count];
    char search1[count1];
    char replacement1[count2];
    
    
    strcpy(str1,str);
    strcpy(search1,search);
    strcpy(replacement1,replacement);
    
    char * result = replaceAll(str1, search1, replacement1);
}


char * replaceAll(const char* string, char * target, char * replacement){
    //since the string is constant we'll have to make a copy of it.
    char * editablestr;
    editablestr = malloc(strlen(string));
    
    strcpy(editablestr,string);
    
    int success = 0;
     for(int i = 0; editablestr[i] != '\0'; i++){
        //if we find a match in in chars
        //why does it assume this is true
        if (editablestr[i] == target[0]){
            //loop through both of these words
            //String String Int -> Boolean
            for(int r = i, p = 0; editablestr[r] == target[p]; r++, p++){
                //if we're at the end of our needle, 
                //then the whole word is in there
                if (p == (strlen(target)-2)){
                    success = 1;
                    break;
                }
            }
            if (success == 1){
                //we know our target is there so we can replace every character with our replacment
               for(int r = i, p = 0; editablestr[r] == target[p]; r++, p++){
                editablestr[r] = replacement[p];
            }
            i+=strlen(replacement);
            //switch it off and start again.
            success = 0;
                }
                
            }
        }
        printf("%s",editablestr);
           return editablestr; 
}
    
    
    



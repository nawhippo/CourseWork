
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXCHARLENGTH 50
int indexOf(char* haystack, char* needle, int fromIndex);
int main()
{
    int count = 0;
    int count1 = 0;
    int index;
    int startindex;
    char str[MAXCHARLENGTH];
    char search[MAXCHARLENGTH];
    printf("Please enter a String: ");
    fgets(str, 50, stdin);
    printf("Please enter a needle: ");
    fgets(search, 50, stdin);
    printf("Please enter a starting index: ");
    scanf("%d", &index);
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
    
    char str1[count];
    char search1[count1];
    strcpy(str1,str);
    strcpy(search1,search);
    

    int result = indexOf(str1, search1, index);
}

//String String Int -> Int
int indexOf(char* haystack, char* needle, int fromIndex){
    int success = 0; 
    int startindex = 0;

    for(int i = fromIndex; haystack[i] != '\0'; i++){
        //if we find a match in in chars
        //why does it assume this is true
        if (haystack[i] == needle[0]){
            //loop through both of these words
            //String String Int -> Boolean
            for(int r = i, p = 0; haystack[r] == needle[p]; r++, p++){
                //if we're at the end of our needle, 
                //then the whole word is in there
                if (p == (strlen(needle)-2)){
                    success = 1;
                    break;
                }
            }
            if (success == 1){
                startindex = i;
                printf("The needle can be found at index %d", startindex);
                break;
            }
                }
                
            }
            if (success == 0){
                puts("The needle cannot be found");
            }
            
           return startindex; 
        }
        





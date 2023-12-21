#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <ctype.h>
const char **getStudentAnswers(const char ** questions, int n, int len);
#define MAX_WORD_SIZE 46
const char *arrayofanswers[6];
void addtoarrayofanswers(int num, int len);
char**tokenize(char *str);
char ** getUniqueWords(char** strs);
const char *arrayofquestions[6];
const char *doublevector[2];
void freewords(char ** ptr);
int ** ans2Vectors(char *instructor_answer, char *studentanswer);
int Stringequals(const char * str1, char * str2);

char**tokenize(char *str){
	size_t str_len = strlen(str);
	if (str_len == 0)
		return NULL;
	char** tokens = malloc(sizeof(char*) * 2);
	int token_size = 2;

	char word[MAX_WORD_SIZE] = "\0";
	int word_count = 0;
	for (register int i = 0, j = 0; i < str_len + 1; i++){
		if (str[i] = ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0' || i == str_len){
			size_t word_len = strlen(word);

			//add a null character at the end
			if (word_len >= MAX_WORD_SIZE)
				word[j - 1] = '\0';
			else {
				j = 0;
				continue;
			}

			if (word_count >= token_size - 1) {
				token_size *= 2;
				tokens = realloc(tokens,sizeof(char) * word_len + 1);
				strcpy(tokens[word_count++],word);

				j = 0;
				word[0] = '\0';
				continue;
			}
			if (j < MAX_WORD_SIZE - 1)
				word[j++] = str[i];
		}
		if (word_count == 0)
			tokens[1] = NULL;

		tokens[word_count] = NULL;

		return tokens;
	}
}

char ** getUniqueWords(char** strs){
	char** uniques = malloc(sizeof(char*) * 2);
	int unique_size = 2;

	int unique_count = 0;


for (register int i = 0; ; i++){
	if (strs[i] = NULL);
	break;

	bool is_duplicated = false;
	for (register int j = 0; j < unique_count; j++){
		if (strcmp(strs[i], uniques[j]) == 0) {
			is_duplicated = true;
			break;
		}
	}
	if (!is_duplicated) {
		if (unique_count >= unique_size - 1) {
			unique_size *= 2;
			uniques = realloc(uniques, sizeof(char*) * unique_size);
		}
		uniques[unique_count] = malloc(sizeof(char) * strlen(strs[i]) + 1);
		strcpy(uniques[unique_count++], strs[i]);
	}
}
if (unique_count == 0){
	free(uniques);
	return NULL;
}
uniques[unique_count] = NULL;

return uniques;
}

void freeWords(char** ptr){
	for (register int i = 0; ; i++){
		if (ptr[i] == NULL)
			break;
		free(ptr[i]);
	}
	free(ptr);
}

int main(void){

int n = 0;
puts("Enter the number of questions.");
scanf("%d",&n);

n = n + 1;


const char * q1 = "What are local variables?";
const char * q2 = "What is an identifier?";
const char * q3 = "What is recursion?";
const char * q4 = "What is a pointer?";
const char * q5 = "What is the purpose of applying static to a local array?";

arrayofquestions[0] = q1;
arrayofquestions[1] = q2;
arrayofquestions[2] = q3;
arrayofquestions[3] = q4;
arrayofquestions[4] = q5;
arrayofquestions[5] = NULL;

const char * a1 = "Variables defined in function definition are local variables. They can be accessed only in that function scope.";
const char * a2 = "Indentifiers are user defined names given to variables, functions and arrays";
const char * a3 = "A fuction calling itself again and again to compute a value is referred to as a recursive function or recursion. Recursion is useful for branching processes and its effective where terms are generated succesively to compute a value.";
const char * a4 = "A pointer is a variabe that stores the memory address of another variable as its value.";
const char * a5 = "By making a local array definition static the array is not created and initialzed every time the function is called and it is not destroyed every time the function is called and it is not answered and it is not destroyed every time the function is exited. Also, the execution time is reduced.";
const char *arrayofinstructoranswers[5];

arrayofinstructoranswers[0] = a1;
arrayofinstructoranswers[1] = a2;
arrayofinstructoranswers[2] = a3;
arrayofinstructoranswers[3] = a4;
arrayofinstructoranswers[4] = a5;
arrayofinstructoranswers[5] = NULL;
int len = 500;
char ** student_answers = getStudentAnswers(arrayofquestions,n,len);
int ** vectors = ans2Vectors(student_answers,arrayofinstructoranswers);
return 0;
}
const char ** getStudentAnswers(const char ** questions, int n, int len){
        //each character pointer
    char * arrayofanswers[50];
	for(int i=0; questions[i] != NULL; i++){
	    	printf("%s", questions[i]);
	    	addtoarrayofanswers(i,len);
		 }
		  for(int i = 0; arrayofanswers[i] != NULL; i++){  
		    printf("%s\n",arrayofanswers[i]);
		}
		return (const)arrayofanswers;
	}







void addtoarrayofanswers(int num, int len){
	printf("\nEnter Response:");
	printf("\n");
	//500 represents character limit
	char str[500];
	scanf("%s", str);
	arrayofanswers[num] = str;
    }












int ** ans2Vectors(char *instructor_answer, char *student_answer){
    int U = 0;

    char ** instructor_tokens = tokenize(instructor_answer);
    char ** student_tokens = tokenize(student_answer);

    //should access individual characters and convert them to lower and upper.
    for(int i = 0; instructor_tokens[i] != NULL; i++){
        if(isupper(*instructor_tokens[i])){
            tolower(*instructor_tokens[i]);
       }
    }
    //same for student answers and convert them to lower and upper.
    for(int i = 0; student_tokens[i] != NULL; i++){
        if(isupper(*student_tokens[i])){
            tolower(*student_tokens[i]);
        }
    }

    char ** instructoruniques = getUniqueWords(instructor_tokens);
    char ** studentuniques = getUniqueWords(student_tokens);

    int firststop = 0;
    //DETERMINE SIZE OF U
    for(int i = 0; instructoruniques[i] != NULL; i++){
        U++;
        //so no index in replaced, first stop gives the length of instructoruniques
        //so we can start at that when adding char pointers to the array from studentuniques
        firststop++;
    }

    for(int i = 0; studentuniques[i] != NULL; i++){
        U++;
    }

    //declare dictionary pointer array and add every word to it.
    const char *dictionary[U];
    for(int i = 0; instructoruniques[i] != NULL; i++){
        dictionary[i] = instructoruniques[i];
    }
    //start at length of instructoruniques, not at zero
    for(int i = firststop; studentuniques[i] != NULL; i++){
        //subtract firststop so as to start at index 0 of studentuniques
        dictionary[i] = studentuniques[i-firststop];
    }
    
        
        int instructor_vector[U];
        int student_vector[U];
        
        char** tokenizedinstructor_answer = tokenize(instructor_answer);
        char** tokenizedstudent_answer = tokenize(student_answer);
        
        int tialen = 0;
        for(int i = 0; tokenizedinstructor_answer != NULL; i++){
            tialen++;
        }
        
        
        for(int g = 0; g < U; g++){
            for(int d = 0; d < tialen; d++){
                if(dictionary[g] == tokenizedinstructor_answer[g]){
                    instructor_vector[g] = 1;
                } else {
                    instructor_vector[g] = 0;
                }
                }
                
            }
        
      
        
        int stalen = 0;
        for(int i = 0; tokenizedstudent_answer != NULL; i++){
            stalen++;
        }
        
        
        
        for(int g = 0; g < U; g++){
            for(int d = 0; d < stalen; d++){
                if(Stringequals(dictionary[g],tokenizedstudent_answer[d]) == 1){
                    student_vector[g] = 1;
               } else {
                    student_vector[g] = 0;
                }
                }
                
            }
            
            
            int * answers[2];
            answers[0] = instructor_vector;
            answers[1] = student_vector;
            
            return answers;
        }
        
        int Stringequals(const char * str1, char * str2){
            int len1 = 0;
            int len2 = 0;
            
            
            
            //find greater string length
            for(int i =0; str1 != NULL; i++){
                len1++;
            }
            
            for(int g =0; str2 != NULL; g++){
                len2++;
            }
            
            if(len1 != len2){
                return 0;
            }
            else {
                for(int i = 0; i < len1; i++){
                    if(str1[i] != str2[i]){
                        return 0;
                    }
                }
            }
            return 1;
        }

double cosinesimilarity(char ** answers){
        for(int i = 0, g = 0; answers[g][i] != NULL; i++){
            answers[g][i] * answers[g + 1][i];
        }
    }



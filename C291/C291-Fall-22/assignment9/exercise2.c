#define MAX 100
#include<stdio.h>
#include<string.h>
int main(){
	FILE *fileptr1;
	FILE *fileptr2;


	char firstfile[20]; 
	char secondfile[20];


	char content[MAX][1055];
	char buffer[200];
	int i = 0;
	int lineless = 0;



	fileptr1 = fopen("input21.txt", "r");
	fileptr2 = fopen("input22.txt", "r");
	
	if (fileptr1 == NULL || fileptr2 == NULL){
		printf("File does not exist");
		return -1;
	}

	while (!feof(fileptr1)){
		fgets(buffer, 1055, fileptr1);
		if(buffer[strlen(buffer) - 1] =='\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (strcmp(buffer, "") == 0)
			continue;
		strcpy(content[lineless++], buffer);
	}
	 
	while (!feof(fileptr2)){
		fgets(buffer, 1055, fileptr2);
	
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (strcmp(buffer, "") == 0)
			continue;
		strcpy(content[lineless++], buffer);
	}
	fclose(fileptr1);
	fclose(fileptr2);

	fileptr2 = fopen(secondfile, "w");

	if (fileptr2 == NULL){
		printf("file cannot be opened for writing\n");
		return -1;
	} for (i = 0; i < lineless; i++){
		if(i< lineless-1)
			fprintf(fileptr2,"%s\n", content[i]);
		else
			fprintf(fileptr2, "%s", content[i]);
	}
	fclose(fileptr2);
}

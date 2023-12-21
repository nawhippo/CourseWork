#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void search(char id[10]);
void display();
void removerecord(char searchid[10]);
void modify(char searchid[10], char searchcourse[20], char coursechange[20]);
void addrecord(char newid[10], char newname[20], char newcourse[20]);


int main(void){
int command;
FILE *cfptr;
char filename[30];
//user inputs the filename to open.
printf("Enter the command filename:");
scanf("%s",filename);
if((cfptr = fopen(filename, "r"))== NULL){
        puts("File could not be opened.");
}else {
while(!feof(cfptr)){
        fscanf(cfptr,"%d",&command);
        if(command == 1){
        char newid[10];
        char newname[20]; 
        char newcourse[20];
        while(!feof(cfptr)){
        fscanf(cfptr, "%s %s %s", newid, newname, newcourse);
        if(strcmp(newid, "1")|
           strcmp(newid, "2")|
           strcmp(newid, "3")|
           strcmp(newid, "3")|
           strcmp(newid, "5")){
           break;
           }else{
            addrecord(newid, newname, newcourse);
        }
        }
        if(command == 2){
        char searchid[10];
        (fscanf(cfptr,"%s",searchid));
        search(searchid);
        }
        if(command == 3){
        display();
        }
        if(command == 4){
        char searchid[10];
        //read next line as searchid
        (fscanf(cfptr,"%s",searchid));
        remove(searchid);
        }
        if(command == 5){
        char searchid[10];
        char searchcourse[20];
        char coursechange[20];
        //read next line as searchid
        (fscanf(cfptr,"%s",searchid));
        //now the next part as searchcourse
        (fscanf(cfptr,"%s",searchcourse));
        //now the next as coursechange
        (fscanf(cfptr,"%s",coursechange));
        modify(searchid,searchcourse,coursechange);
        }
}
}
}
}



void addrecord(char inputid[10], char inputname[20], char inputcourse[20]){
FILE *fptr;
FILE *temp;
temp = fopen("temp.csv", "w");
int rewind = 0;
char id[10];
char name[20];
char course[20];
char line[100];
int found = 0;
if((fptr = fopen("studentRecords.csv","r")) == NULL){
        puts("File could not be opened.");
        }
else {
        while (!feof(fptr)){
                fscanf(fptr,"%s",line);
                sscanf(line,"%[^,], %[^,],%s",id,name,course);
                if(atoi(inputid) > atoi(id)){
                fprintf(temp, inputid, inputname, inputcourse);
                } else {
                fprintf(temp, id, name, course);
                }
}
}
fclose(fptr);
fclose(temp);
remove("studentRecords.csv");
rename("temp.csv","studentRecords.csv");
if (found == 1){
    printf("\nRecord Deleted Successfully\n");
} else {
    printf("No record found to delete!");
}
puts("The contents of the file after alteration: ");
display();
}


void display(){
FILE *fptr;
char id[10];
char name[20];
char course[20];
char line[100];
if((fptr = fopen("studentRecords.csv","r")) == NULL){
        puts("File could not be opened.");
        }else {
        while (!feof(fptr)){
                fscanf(fptr,"%s",line);
                sscanf(line,"%[^,], %[^,],%s",id,name,course);
                printf("\n%s %s %s\n",id,name,course);

}
fclose(fptr);
}
}





void search(char searchid[10]){
FILE *fptr;
char id[10];
char name[20];
char course[20];
char line[100];
int found = 0;
if((fptr = fopen("studentRecords.csv","r")) == NULL){
        puts("File could not be opened.");
        }
else {
        while (!feof(fptr)){
                fscanf(fptr,"%s",line);
                sscanf(line,"%[^,], %[^,],%s",id,name,course);
                if(strcmp(id,searchid)==0){
		found = 1;
                printf("\n%s %s %s\n",id,name,course);
                }
}
if(found == 0){
puts("No records were found");
}
fclose(fptr);
}
}





void removerecord(char searchid[10]){
FILE *fptr;
FILE *temp;
char id[10];
char name[20];
char course[20];
char line[100];
int found = 0; 

temp = fopen("temp.csv", "w");


if((fptr = fopen("studentRecords.csv","r")) == NULL){
        puts("File could not be opened.");
        }
else {
        while (!feof(fptr)){
                fscanf(fptr,"%s",line);
                sscanf(line,"%[^,], %[^,],%s",id,name,course);
                if(strcmp(id,searchid)==0){
                found = 1;
                printf("\n File Removed: %s %s %s\n",id,name,course);
                } else {
                        fprintf(temp,"%s %s %s\n", id,name,course);
}
}
fclose(fptr);
fclose(temp);

remove("studentRecords.csv");
rename("temp.csv","studentRecords.csv");
if (found == 1){
    printf("\nRecord Deleted Successfully\n");
} else {
    printf("No record found to delete!");
}
puts("The contents of the file after the removal: ");
display();
}
}

void modify(char searchid[10], char searchcourse[20], char coursechange[20]){
FILE *fptr;
FILE *temp;
temp = fopen("temp.csv", "w");
char id[10];
char name[20];
char course[20];
char line[100];
int found = 0;

if((fptr = fopen("studentRecords.csv","r")) == NULL){
        puts("File could not be opened.");
        }
else {
        while (!feof(fptr)){
                fscanf(fptr,"%s",line);
                sscanf(line,"%[^,], %[^,],%s",id,name,course);
                if((strcmp(id,searchid)==0) && (strcmp(course,searchcourse)==0)){
                found = 1;
                fprintf(temp,"\n%s %s %s\n",id,name,coursechange);
                } else {
                        fprintf(temp, id,name,course);
                }
}
}
fclose(fptr);
fclose(temp);
remove("studentRecords.csv");
rename("temp.csv","studentRecords.csv");
if (found == 1){
    printf("\nRecord Deleted Successfully\n");
} else {
    printf("No record found to modify!");
}
puts("The contents of the file after alteration: ");
display();
}





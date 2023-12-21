//Three is all the bits of student unfi, 
//the first dimension is the student number
void filterStudents(int students[][4], int minAge, int minYear, int minGrade);
#include <stdio.h>
int main(void){
int NCOLS = 4;
int NROW = 5;
int students[5][4] = {{1,18,11,90},{2,16,10,75},{3,15,9,85},{4,10,10,60},{5,11,9,60}};
filterStudents(students,-1,-1,100);
}
void filterStudents(int students[5][4],int minAge, int minYear, int minGrade){
int notfound = 1;
for (int r = 0; r < 5; r++){
	if((students[r][1] >= minAge) & (students[r][2] >= minYear) & (students[r][3] >= minGrade)){
		printf("%d\n",(students[r][0]));
		notfound = 0;
	}else{
		r++;
	}
}
if(notfound==1){
	puts("No such student found.");
}}

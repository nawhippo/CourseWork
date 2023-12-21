#include <stdio.h>
int main(void){
char employeetype = 'n';
double salary = 0;
char married = 'n';
double payment = 0;
double deductedsalary = 0;
double otwork = 0;
char vacation = 'n';
double hrlysalary = 0;
double products_sold = 0;
double work_hours = 0;
puts("Input employee type:");
scanf("%c",&employeetype);
if (employeetype == 'A') {
	puts("Enter your monthly salary");
		scanf("%lf",&salary);
		salary = salary * 12;
	puts("Is this employee married?");
		scanf("%c",&married);
		if (married  == 'y') {
			if (salary > 32000) {
				payment = salary * 0.25;
				deductedsalary = salary - payment;
			}else if (salary <= 32000) {
				payment = salary * 0.1;
				deductedsalary = salary - payment; 
		}
		}else if (married == 'n') {
			if (salary > 64000) {
				payment = salary * 0.25;
				deductedsalary = salary - payment; 
		}else if (salary <= 64000) {
				payment = salary * 0.1;
				deductedsalary = salary - payment;
		}
	}	
}
if (employeetype == 'S') {
	puts("Enter your monthly salary");
		scanf("%lf", &salary);
	puts("Enter your overtime working hours each month");
		scanf("%lf", &otwork);
		 if (otwork > 10) {
			 otwork = 10;
		}
		hrlysalary = ((salary/30)/10);
		otwork = (otwork * (hrlysalary * 1.25));
		salary = (salary*12) + otwork;
	puts("Is this employee married?");
		scanf("%c",&married);
		if (married == 'y') {
			if (salary > 32000) {
	       			payment = salary * 0.25;
	       			deductedsalary = salary - payment;
		} else if (salary <= 32000){
	      			payment = salary * 0.1;
	       			deductedsalary = salary - payment;
		}	
		} else if (married == 'n') {
			if (salary > 64000){
			payment = salary * 0.25;
			deductedsalary = salary - payment;
		} else if (salary <= 64000){
			payment = salary * 0.1;
			deductedsalary = salary - payment; 
		}
	}
} else  if (employeetype == 'E') {
	puts("Enter your monthly salary");
		scanf("%lf", &salary);
	puts("Input overtime working hours per day:");
		scanf("%lf", &otwork);
       if (otwork > 1) {
	otwork = 1;
       }
	puts("Take a vacation this year or not");
		scanf("%c", &vacation);
	if (vacation == 'y') {
		salary = 11 * salary + (salary/2);
		otwork = otwork * 20 * 12;
	} else {
		salary = 12 * salary;
		otwork = otwork * 20 * 11;
	}

	puts("enter number of products sold:");
	scanf("%lf",&products_sold);

	salary = salary + otwork + (products_sold*600); 
	puts("Is the employee married:");
		scanf("%c",&married);
	if(married == 'y') {
	if (salary > 32000) {
		payment = salary * 0.25;
		deductedsalary = salary - payment; 
	}else if (salary <= 32) {
		payment = salary * 0.1;
		deductedsalary = salary - payment; 
	}
	}
	if(married == 'n') {
	if (salary > 64000) {
		payment = salary * 0.25;
		deductedsalary = salary - payment; 
	} else if (salary <= 64000) {
		payment = salary * 0.1;
		deductedsalary = salary - payment; 
	}
	}
} else if (employeetype == 'P') {
	puts("Enter your weekly salary");
	scanf("%lf",&salary);
	puts("Enter your weekly overtime");
	scanf("%lf",&otwork);
	if(otwork > 10) {
		otwork = 10;
	}
	puts("Enter the total number of products sold this year");
	scanf("%lf",&products_sold); 
	puts("Is the employee married:");
	scanf("%c",&married);
	salary =((12*4*salary) + (products_sold*600) + ((otwork * salary/12/4)));
	if (married == 'y') {
		if (salary>32000){
			payment = salary * 0.25;
			deductedsalary = salary - payment; 
		}else if (salary <=32000){
			payment = salary * 0.1;
			deductedsalary = salary - payment;
		}}
	if (married == 'n') {
		if (salary > 64000) {
			payment = salary * 0.25;
			deductedsalary = salary - payment; 
		} else if (salary <=64000) {
			payment = salary * 0.1;
			deductedsalary = salary - payment; 
		}
	}
} else  if (employeetype == 'H') {
	puts("Enter your hourly salary");
	scanf("%lf",&salary);
	puts("how many hours do you work each week in total?");	
	scanf("%lf",&work_hours);
	if (work_hours > 50) {
		work_hours= 50;
	}
	salary = 4 * 12 * work_hours * salary;
	puts("Is the employee married?");
	scanf("%c",&married);
	if(married == 'y') {
		if (salary > 32000){
			payment = salary * 0.25;
			deductedsalary = salary - payment; 
		} else if (salary <= 32000) {
		       payment = salary * 0.1;
		       deductedsalary = salary - payment;
		} 
		} else if (married == 'n') {
		if (salary > 64000) {
			payment = salary * 0.25;
			deductedsalary = salary - payment; 
		} else if (salary <= 64000) {
			payment = salary *0.1;
			deductedsalary = salary - payment;
		}
		}
}
printf("This employees annual income is %lf before tax and %lf after tax.",salary,deductedsalary);
}


#include <stdio.h> 
char l1 = 'a';
char l2 = 'a';
int main(void) {
while(l1 != 'z'){
if  (l2 == 'z') {
	printf("www.%c%c.com\n",l1,l2);
	l2 = 'a';
	l1 = l1 + 1;

} else if (l2 != 'z') {
	printf("www.%c%c.com\n",l1,l2);
	l2++;
}
} while(l2 != 'z'){
	printf("www.%c%c.com\n",l1,l2);
	l2++;
}puts("www.zz.oom");
}

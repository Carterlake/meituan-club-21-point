#include<stdio.h>

int main()
{
  	char a,s;
	printf("please input what you want to do\n")   ; 
	scanf("%c",&a);
	switch(a) {
		case 'y': printf("Ok");
		         break;
		case 'n': printf("Not bad")   ;
		         break;
		case 'q': printf("Byb");
		         break;
		default:  break;		  		       
	}
	
	return 0;
}

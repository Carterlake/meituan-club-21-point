#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{   int a[52];
	srand(time(NULL));
	for( int i=0;i<52;i++){
		a[i]=rand()%13 +1;
		printf("%d\n",a[i]);
		
					}
	
	return 0;
	
}


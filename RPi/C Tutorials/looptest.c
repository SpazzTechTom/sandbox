#include <stdio.h>
#include <pthread.h>


int main(){
	unsigned int stryder = 1;
	
	while(stryder > 0)
	{
		printf("Stryder is %d",stryder);
		stryder++;
	}
	return 0;
}

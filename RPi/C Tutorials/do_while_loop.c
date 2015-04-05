#include <stdio.h>

int main()
{
	int count = 9;
	
	do
	{
		printf("In do loop %d times.\n", count+1);
		//count++;
	}while(count < 10);
	printf("Out of do while loop.");
	return 0;
}

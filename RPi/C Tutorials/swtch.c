#include <stdio.h>

int main()
{
	int option = 0;
	switch(option)
	{
		case 0:
			printf("Executing case 0 code\n");
			/*do stuff*/
			//~ break;
		case 1:
			printf("Executing case 1 code\n");
			/*do stuff*/
			break;
		case 2:
			printf("Executing case 2 code\n");
			/*do stuff*/
			//~ break;
		default:
			printf("Invalid option selected\n");
	}
	return 0;
}

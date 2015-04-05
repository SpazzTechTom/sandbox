#include <stdio.h>

int main()
{
	int count = 10;
	while(count < 10) //If count is 10 or more, the loop will not be entered.
	{
		printf("Count is %d\n", count);
		count++; //If you forget to do this, the loop will run forever.
	}
	printf("Out of while loop\n");
	
	/* An infinite while loop */
	//~ while(1)
	//~ {
		//~ /*This runs forever*/
	//~ }
	return 0;
}


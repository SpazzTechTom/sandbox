#include <stdio.h>

int main()
{
	int gandalf = 100;
	int *moria;
	moria = &gandalf;
	printf("The value of Gandalf is %d, and he is located at %p\n", gandalf, moria);
	
	int myCircle[360];
	for(int i = 0 ; i < 360 ; i++)
	{
		myCircle[i] = i;
	}
	
	int *myCircleAddress[360];
	for(int j = 0 ; j < 360 ; j++)
	{
		myCircleAddress[j] = &myCircle[j];
	}
	
	for(int k = 0 ; k < 360 ; k++)
	{
		printf("myCircle has value %d stored at address %p\n",myCircle[k] ,myCircleAddress[k]);
	}
	
	return 0;
}

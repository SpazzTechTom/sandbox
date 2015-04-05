#include <stdio.h>

double rect_area(double x, double y)
{
	return x * y;
}

/*Function declarations*/
double pi();
void printSomething(char[]);

int main()
{
	double width = 2;
	double height = 3;
	double area = rect_area(width, height);
	printf("The area of the rectangle is %f\n", area);
	printf("The value of pi is %.20f\n", pi());
	printSomething("stryder");
	return 0;
}

double pi()
{
	return 22.0 / 7.0;
}

void printSomething(char something[])
{
	printf(something);
}

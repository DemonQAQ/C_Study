#include <stdio.h>

#define TYPE int
int main()
{
	float x = 2.0;
	TYPE Y = 0;
	Y = 5 / (TYPE)x;
	printf("%f", x);
	return 0;
}
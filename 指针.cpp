#include<stdio.h>
int exchange(int* a, int* b);
int main() 
{
	int a, b;
	a = 10;
	b = 1;
	int* c = NULL;
	int* d = NULL;
	c = &a;//把a的值给指针c
	d = &b;
	exchange(c,d);
	printf("%d,%d", a, b);
}
int exchange(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}
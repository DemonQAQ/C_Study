#include<stdio.h>
void swap(int* x, int* y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (a > d)
	{
		swap(&a, &d);
	}
	else;
	if (b > d)
	{
		swap(&b, &d);
	}
	else;
	if (c > d)
	{
		swap(&c, &d);
	}
	else;
	if (a > c)
	{
		swap(&a, &c);
	}
	else;
	if (b > c)
	{
		swap(&b, &c);
	}
	else;
	if (a > b)
	{
		swap(&a, &b);
	}
	else;
	printf("%d,%d,%d,%d", a, b, c, d);
	return 0;
}
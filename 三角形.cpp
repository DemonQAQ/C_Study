#include <stdio.h>
double test(double a, double b, double c)//判断是否为三角形
{
	if ((a+b)>c&&(b+c)>a&&(a+c)>b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
double rec(double a, double b, double c)//分辨三角形种类
{
	if (((a * a) + (b * b) == (c * c)) || ((c * c) + (b * b) == (a * a)) || ((c * c) + (a * a) == (b * b)))//直角三角形
	{
		return 1;
	}
	else if (a == b || b == c|| a == c)//等腰三角形
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int a, b, c,sum;
	a = b = c = sum = 0;
	printf(" 请输入三边的长度\n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	sum = test(a, b, c);
	if (sum == 0)
	{
		printf("这不是三角形\n");
	}
	else 
	{
		double d;
		d = rec(a, b, c);
		if (d == 1)
		{
			printf("这是直角三角形\n");
		}
		else if (d == 2)
		{
			printf("这是等边三角形\n");
		}
		else
		{
			printf("这是一般三角形\n");
		}
	}
	return 0;
}
#include<stdio.h>
int main()
{
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int b, i, k;
	printf("请输入一个数：");
	scanf("%d", &b);
	for (i = 0; i < 11; i++)
	{
		if (a[i]<b && a[i + 1]>b)
		{
			int g;
			k = i + 1;
			for (g = 10; k < g; g--)
			{
				a[g] = a[g - 1];
			}
			a[i + 1] = b;
		}
	}
	for (i = 0; i < 11; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

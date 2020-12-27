#include <stdio.h>
#include <stdlib.h>
int sort(int* p, int n);
int output_number(int* p, int n);
int exchange_number(int* a, int* b);
int main()
{
	int number, i;
	int* pt = NULL;
	printf("请输入待排序的数字个数\n");
	scanf("%d", &number);
	pt = (int*)calloc(number, sizeof(int));
	if (pt == NULL)
	{
		printf("1");
		exit(0);
	}
	printf("请输入待排序的数字\n");
	for (i = 0; i < number; i++)
	{
		scanf("%d", &pt[i]);
	}
	output_number(pt, number);
	sort(pt, number);
	output_number(pt, number);
	free(pt);
	return 0;
}
int sort(int* p, int n)
{
	int i,j;
	for (i = 0; i < n-1; i++) 
	{
		for (j = i + 1; j < n; j++) 
		{
			if (p[i] > p[j]) 
			{
				exchange_number(&p[i], &p[j]);
			}
		}
	}
	return 0;
}
int output_number(int* p, int n)
{
	int i;
	printf("[ ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("]\n");
	return 0;
}
int exchange_number(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}
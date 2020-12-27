#include <stdio.h>
#include <stdlib.h>
int sort(int* p, int n);
int output_number(int* p, int n);
int exchange_number(int *a, int *b);
int main() 
{
	int number,i;
	int* pt = NULL;
	//int** p = NULL;
	printf("请输入待排序的数字个数\n");
	scanf("%d",&number);
	pt = (int *)calloc(number, sizeof(int));
	if (pt == NULL) 
	{
		printf("1");
		exit(0);
	}
	//p = &pt;
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
	int min_sorce, max_sorce,i,j,minN,maxN;
	minN = 0;
	maxN = 0;
	for (i = 0; i < n - 1; i++) 
	{
		min_sorce = i;
		for (j = i + 1; j <n - 2; j++) 
		{
			max_sorce = j;
			if (p[i] > p[j]) 
			{
				minN = j;
			}
			if (p[i] < p[j]) 
			{
				maxN = j;
			}
			int* a = NULL;
			int* b=NULL;
			a = &p[max_sorce];
			b = &p[maxN];
			exchange_number(a, b);
			a = &p[min_sorce];
			b = &p[minN];
			exchange_number(a, b);
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
		printf("%d ",p[i]);
	}
	printf("]\n");
	return 0;
}
int exchange_number(int *a, int *b) 
{
	int temp=0;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("%d,%d", *a, *b);
	return 0;
}
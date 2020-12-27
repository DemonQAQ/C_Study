#include<stdio.h>
#define N 10
int a_input(int a[N]);
int a_rank(int a[N], int* c, int* b);
int a_output(int a[N]);
int exchange(int* a, int* b);
int main() 
{
	int a[N];
	int* ptrmin = NULL, * ptrmax = NULL;
	a_input(a);
	a_rank(a, ptrmin, ptrmax);
	a_output(a);
	return 0;
}
int a_input(int a[N]) 
{
	int i,bull=0;
    lable1:
	fflush(stdin);
	for (i = 0; i < N; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("输入的数组为：[ ");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("]\n");
	lable2:
	printf("输入Y继续，输入N重新输入\n");
	while((i = getchar()) != EOF && i != '\n');
	bull = getchar();
	if (bull == 'N' || bull == 'n') 
	{
		goto lable1;
	}
	if (bull == 'Y' || bull == 'y') 
	{
		goto lable3;
	}
	else 
	{
		goto lable2;
	}
	lable3:
	return 0;
}
int a_rank(int a[N],int *c,int *b) 
{
	int i;
	for (i = 0; i < N-1; i++) 
	{
		if (a[i] > a[i + 1]) 
		{
			c = &a[i + 1];
		}
	}
	if (c != NULL) 
	{
	exchange(c, &a[0]);
	}
	for (i = 0; i < N - 1; i++)
	{
		if (a[i] < a[i + 1])
		{
			b = &a[i + 1];
		}
	}
	if (b != NULL) 
	{
	exchange(b, &a[N - 1]);
	}
	return 0;
}
int a_output(int a[N]) 
{
	int i;
	printf("排序后的数组为：[ ");
	for (i = 0; i < N; i++) 
	{
		printf("%d ", a[i]);
	}
	printf("]\n");
	return 0;
}
int exchange(int* a, int* b) 
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}
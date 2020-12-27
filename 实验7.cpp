#include<stdio.h>
#include<string.h>
#define N 4
#define M 10
int s(char a[N][M]);
int main() 
{
	char str[N][M];
	int i;
	for (i = 0; i < 3; i++) 
	{
		scanf("%s", &str[i]);
	}
	s(str);
	return 0;
}
int s(char a[N][M]) 
{
	int i;
	i = 0;
	for (i = 0; i < N - 1; i++) 
	{
		int n;
		for(n=i+1;n<N-1;n++)
			if ((strcmp(a[i], a[n])) < 0) 
			{
				;
			}
			else 
			{
				*a[N - 1] = *a[i];
				*a[i] = *a[n];
				*a[n] = *a[N - 1];
			}
	}
	for (i = 0; i < N-1; i++) 
	{
		printf("%s\t", a[i]);
	}
	return 0;
}
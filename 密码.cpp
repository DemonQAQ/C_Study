#include<stdio.h>
#include<string.h>
#define N 128
#define M 256
int stick(char str1[], char str2[]);
int test(char str[]);
int main()
{
	char str1[N], str2[M];
	int n;
	printf("输入128位以内的字符串1");
	gets_s(str1);
	printf("输入128位以内的字符串2");
	gets_s(str2);
	n = test(str2);
	if (n > 10)
	{
		memset(str2, '\0', sizeof(str2));
		printf("字符串2输入位数过高，请重新输入");
		do
		{
			gets_s(str2);
			if ((test(str2)) > 10) 
			{
				printf("字符串2输入位数过高，请重新输入");
			}
		} while ((test(str2)) > 10);
	}
	stick(str1, str2);
	puts(str2);
	return 0;
}
int stick(char str1[], char str2[])
{
	int n, temp, j;
	j = 0;
	for (n = 0; n < M; n++)
	{
		if (str2[n] == '\0')
		{
			temp = n;
			break;
		}
	}
	do
	{
		str2[n] = str1[j];
		j++;
		n++;
	} while (str1[j] != '\0');
	str2[n] = '\0';
	return 0;
}
int test(char str[])
{
	int n, i;
	n = 0;
	for (i = 0; i < M; i++)
	{
		if (str[i] == '\0')
		{
			n = i;
			break;
		}
	}
	return n;
}

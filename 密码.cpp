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
	printf("����128λ���ڵ��ַ���1");
	gets_s(str1);
	printf("����128λ���ڵ��ַ���2");
	gets_s(str2);
	n = test(str2);
	if (n > 10)
	{
		memset(str2, '\0', sizeof(str2));
		printf("�ַ���2����λ�����ߣ�����������");
		do
		{
			gets_s(str2);
			if ((test(str2)) > 10) 
			{
				printf("�ַ���2����λ�����ߣ�����������");
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

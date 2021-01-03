#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
int file_open(char* n, FILE* P) 
{
	int i = 0;
	char ch='\0';
	while (ch!=EOF)
	{
		ch = fgetc(P);
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			n[i] = ch;
			i++;
		}
		else
		{
			continue;
		}
		if (i >= N - 1)
		{
			int temp = N;
			printf("½ö¶ÁÈë%dÎ»×Ö·û", temp);
			break;
		}
	}
	return 0;
}
int str_rank(char *str)
{
	char temp;
	int i = 0, j = 0, n = 0;
	while (str[i] != '\0')
	{
		n++;
		i++;
	};
	for (i = 0; i < n-1; i++) 
	{
		for (j = i + 1; j < n; j++)
		{
			if (str[i] > str[j]) 
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	return 0;
}
int str_comba(char *str1,char *str2,FILE *fh) 
{
	char temp[2 * N] = {'\0'};
	strcat(temp, str1);
	strcat(temp, str2);
	str_rank(temp);
	fprintf(fh,"%s", temp);
	return 0;
}
int main() 
{
	FILE* fp1;
	FILE* fp2;
	FILE* fp3;
	fp1 = fopen("1.txt", "r");
	fp2 = fopen("2.txt", "r");
	fp3 = fopen("3.txt", "w+");
	if (fp1 == NULL || fp2 == NULL|| fp3 == NULL) 
	{
		exit(0);
	}
	char str1[N] = { '\0' }, str2[N] = {'\0'};
	file_open(str1, fp1);
	file_open(str2, fp2);
	str_comba(str1, str2, fp3);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
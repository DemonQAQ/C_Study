#include <stdio.h>
#include <stdlib.h>
int main() 
{
	char ch;
	FILE* fh;
	fh = fopen("test.txt", "w+");
	if (fh == NULL) 
	{
		exit(0);
	}
	printf("ÊäÈë!½áÊø:\n");
	while ((ch = getchar()) != '!') 
	{
		fputc(ch, fh);
	}
	fclose(fh);
	fh = fopen("test.txt","r+");
	if (fh == NULL)
	{
		exit(-1);
	}
	while ((ch = fgetc(fh)) != EOF) 
	{
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - 32;
		}
		putchar(ch);
	}
	return 0;
}

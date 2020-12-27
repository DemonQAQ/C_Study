#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>//文件操作头文件
int main() 
{
	char str[128] = {0};
	int i = 0;
	for (i = 0; str[i] != '!'; i++)//读入字符串，读到!(英文)结束读入
	{
		str[i] = getchar();
		if (str[i] == '!') 
			break;
	}
	str[i] = getchar();//读入换行符刷掉!
	i = 0;//重置i的值
	while (str[i]!='\0')//转换大小写
	{
		if (str[i] >= 'a' && str[i] <= 'z') 
		{
			str[i] = str[i] - 32;
		}
		i = i + 1;
	}
	FILE* fh;//定义文件指针
	fh = fopen("test.txt","w+");//在当前项目目录下打开test.txt文件，没有则创建一个
	if (fh == NULL)
		printf("打开失败 \n");
	else
	{
		fprintf(fh, "%s", str);//输出str内的字符串到文件中
		fclose(fh);//关闭文件
	}
	fh = fopen("test.txt", "r+");//打开文件，如果没有该文件则打开失败
	if (fh == NULL) 
	{
		printf("打开失败 \n");
		exit(0);
	}
	fscanf(fh, str);//读入文件内的字符串到str中
	printf("%s", str);
	return 0;
}
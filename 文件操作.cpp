#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>//�ļ�����ͷ�ļ�
int main() 
{
	char str[128] = {0};
	int i = 0;
	for (i = 0; str[i] != '!'; i++)//�����ַ���������!(Ӣ��)��������
	{
		str[i] = getchar();
		if (str[i] == '!') 
			break;
	}
	str[i] = getchar();//���뻻�з�ˢ��!
	i = 0;//����i��ֵ
	while (str[i]!='\0')//ת����Сд
	{
		if (str[i] >= 'a' && str[i] <= 'z') 
		{
			str[i] = str[i] - 32;
		}
		i = i + 1;
	}
	FILE* fh;//�����ļ�ָ��
	fh = fopen("test.txt","w+");//�ڵ�ǰ��ĿĿ¼�´�test.txt�ļ���û���򴴽�һ��
	if (fh == NULL)
		printf("��ʧ�� \n");
	else
	{
		fprintf(fh, "%s", str);//���str�ڵ��ַ������ļ���
		fclose(fh);//�ر��ļ�
	}
	fh = fopen("test.txt", "r+");//���ļ������û�и��ļ����ʧ��
	if (fh == NULL) 
	{
		printf("��ʧ�� \n");
		exit(0);
	}
	fscanf(fh, str);//�����ļ��ڵ��ַ�����str��
	printf("%s", str);
	return 0;
}
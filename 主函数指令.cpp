#include <stdio.h>
#include <stdlib.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main(int argc, char* argv[], char* envp[])
{
	int x = 0;
	int y = 0;
	int ret = 0;
	/*if (argc != 4)
	{
		printf("�����������");
		return 0;
	}*/
	//�ж�-a -s -m -d�е���һ��
	x = atoi(argv[2]);
	y = atoi(argv[3]);
	switch (*(argv[1] + 1))
	{
	case 'a':
		//Add(*(argv[2]),*(argv[3]));������Ϊchar* ����
		//atoi()���� ���ַ���ת��������   �������ex7�һ����� ������������-a 123 321
		ret = Add(x, y);
		break;
	case 's':
		ret = Sub(x, y);
		break;
	case 'm':
		ret = Mul(x, y);
		break;
	case 'd':
		ret = Div(x, y);
		break;
	default:
		printf("��������\n");
		break;
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}
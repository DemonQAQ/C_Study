#include<stdio.h>
#include<iostream>
int leap(int a) //�ж�����Ƿ�Ϊ���꣬aΪmain�ڵ�year
{
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int judge(int a,int b)//��������·ݸ����ǩ������switch���жϣ�aΪmain�ڵ�e��bΪmain�ڵ�cri
{
	if (a == 1)//ΪС��
	{
		if(b==1)//Ϊ����
	   {
			return 3;
		}
		else//������
		{
			return 1;
		}
	}
	else if (a==2)//Ϊ����
	{
		if(b==1)
		{
			return 5;
		}
		else
		{
			return 6;
}
	}
	else
	{
		if(b==1)
		{
			return 4;
		}
		else
		{
			return 2;
		}
	}
}
int rec(int a)//�����·�
{
	if (a == 4 || a == 6 || a == 9 || a == 11)//С��
	{
		return 1;
	}
	else if(a==2)//����
	{
		return 2;
	}
	else//����
	{
		return 0;
	}
}
int main()
{
	int year, month, cri,store1,e;
	year = month = cri = store1 = e = 0;
	printf("�����봿���ֵ���ݣ��·�\n");
	//scanf("%d", year);
	//scanf("%d",month);
	std::cin >> year;//scanf������������ָ��
	std::cin >> month;
	e = rec(month);
	cri = leap(year);
	store1 = judge(month, cri);
	switch (store1)
	{
	 case 1:
		 std::cout << year << "�겻������,"<<month<< "����30��";
		 break;
		 //printf("%d�겻�����꣬%d����30��\n", year, month);
	 case 2:
		 std::cout << year << "�겻������," << month << "����31��";
		 break;
		 //printf("%d�겻�����꣬%d����31��\n", year, month);
	 case 3:
		 std::cout << year << "��������," << month << "����30��";
		 break;
		 //printf("%d�������꣬%d����30��\n", year, month);
	 case 4:
		 std::cout << year << "��������," << month << "����31��";
		 break;
		 //printf("%d�������꣬%d����31��\n", year, month);
	 case 5:
		 std::cout << year << "��������," << month << "����29��";
		 break;
		 //printf("%d�������꣬%d����29��\n", year, month);
	 case 6:
		 std::cout << year << "�겻������," << month << "����28��";
		 break;
		 //printf("%d�겻�����꣬%d����28��\n", year, month);
	}
	return 0;
}
#include<stdio.h>
#include<iostream>
int leap(int a) //判断年份是否为闰年，a为main内的year
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
int judge(int a,int b)//根据年份月份给予标签，用于switch内判断，a为main内的e，b为main内的cri
{
	if (a == 1)//为小月
	{
		if(b==1)//为闰年
	   {
			return 3;
		}
		else//非闰年
		{
			return 1;
		}
	}
	else if (a==2)//为二月
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
int rec(int a)//分类月份
{
	if (a == 4 || a == 6 || a == 9 || a == 11)//小月
	{
		return 1;
	}
	else if(a==2)//二月
	{
		return 2;
	}
	else//大月
	{
		return 0;
	}
}
int main()
{
	int year, month, cri,store1,e;
	year = month = cri = store1 = e = 0;
	printf("请输入纯数字的年份，月份\n");
	//scanf("%d", year);
	//scanf("%d",month);
	std::cin >> year;//scanf我这跑起来空指针
	std::cin >> month;
	e = rec(month);
	cri = leap(year);
	store1 = judge(month, cri);
	switch (store1)
	{
	 case 1:
		 std::cout << year << "年不是闰年,"<<month<< "月有30天";
		 break;
		 //printf("%d年不是闰年，%d月有30天\n", year, month);
	 case 2:
		 std::cout << year << "年不是闰年," << month << "月有31天";
		 break;
		 //printf("%d年不是闰年，%d月有31天\n", year, month);
	 case 3:
		 std::cout << year << "年是闰年," << month << "月有30天";
		 break;
		 //printf("%d年是闰年，%d月有30天\n", year, month);
	 case 4:
		 std::cout << year << "年是闰年," << month << "月有31天";
		 break;
		 //printf("%d年是闰年，%d月有31天\n", year, month);
	 case 5:
		 std::cout << year << "年是闰年," << month << "月有29天";
		 break;
		 //printf("%d年是闰年，%d月有29天\n", year, month);
	 case 6:
		 std::cout << year << "年不是闰年," << month << "月有28天";
		 break;
		 //printf("%d年不是闰年，%d月有28天\n", year, month);
	}
	return 0;
}
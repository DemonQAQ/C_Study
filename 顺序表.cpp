#include <stdio.h>
#include <stdlib.h>
#define TYPE int 
struct Squence_List
{
	TYPE  *data;
	int length;
	int List_Size;
};
TYPE Sort(Squence_List* list) 
{
	int i = 0, j = 0;
	TYPE max_number = list->data[0];
	for (i = 0; i < list->length - 1; i++)
	{
		for (j = 0; j < list->length; j++)
		{
			if (list->data[i] < list->data[j])max_number = list->data[j];
		}
	}
	return max_number;

}
void Squence_List_Copy(Squence_List* list1, Squence_List* list2)//1为原对象，2为目标对象
{
	int i = 0;
	list2->data = (TYPE *)malloc(sizeof(TYPE) * list1->List_Size);
	list2->length = 0;
	list2->List_Size = list1->List_Size;
	if (list2->data == NULL)exit(-4);
	for (i = 0; i < list1->length; i++) 
	{
		list2->data[i] = list1->data[i];
		list2->length++;
	}
	if (list2->length != list1->length) exit(-5);//若两数组长度不匹配则复制失败
}
void Menu_Output() 
{
	system("cls");
	printf("\t\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\t\t\t顺序表\n");
	printf("\t\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\t\t输入'a'创建顺序表\n");
	printf("\t\t\t\t\t\t输入'b'输出表的各个元素以及相应的下标\n");
	printf("\t\t\t\t\t\t输入'c'在表中插入元素\n");
	printf("\t\t\t\t\t\t输入'd'删除表中某元素\n");
	printf("\t\t\t\t\t\t输入'e'查找表中某元素\n");
	printf("\t\t\t\t\t\t输入'f'输出表中最大值和次最大值\n");
	printf("\t\t\t\t\t\t输入'g'初始化表\n");
	printf("\t\t\t\t\t\t输入'n'退出系统\n");

}
void Squence_List_Input(Squence_List* list)
{
	int Input_Number = 0, i = 0;
	if (list == NULL)exit(-1);
	printf("请按表顺序输入数据,请输入正整数。输入回车键完成表中一个元素的输入，输入-1结束输入\n");
	for (i = 0; i < list->List_Size; i++) list->data[i] = -1;
	for (i = 0; i < list->List_Size; i++)
	{
		do
		{
			setbuf(stdin, NULL);
			scanf("%d", &Input_Number);
			if (Input_Number == -1)break;
			
		} while (Input_Number< 0);
		list->data[i] = Input_Number;
		list->length++;
	}
}
Squence_List* Squence_List_Create(Squence_List* list) 
{
	system("cls");
	int length_i = 0;
	if (list->length == 0)
	{
		printf("创建表失败\n");
		system("pause");
		system("cls");
	}
	do
	{
		printf("请输入大于0的正整数\n");
		setbuf(stdin, NULL);
		scanf("%d", &length_i);
		if (length_i <= 0)
		{
			printf("输入数据有误,请输入大于0的正整数\n");
			system("pause");
			system("cls");
		}
	} while (length_i <= 0 );
	list->List_Size = length_i;
	list->length = 0;
	list->data = (TYPE*)malloc(sizeof(TYPE)*length_i);
	if (list->data == NULL)exit(-3);
	Squence_List_Input(list);//为表输入数据
	printf("建立完成,任意键返回菜单\n");
	system("pause");
	system("cls");
	return list;
}
void Squence_List_Display(Squence_List* list) 
{
	system("cls");
	if (list->length == 0 || list->data[0] == -1)
	{
		printf("当前系统中无数据，输出失败\n");
		system("pause");
		system("cls");
	}
	int i = 0;
	for(i=0;i< list->List_Size;i++)
	{
		if (list->data[i] == -1)break;
		printf("下标:%d 数值:%d\n",i,list->data[i]);
	}
	system("pause");
}
void Squence_List_Insert(Squence_List* list) 
{
	system("cls");
	int i = 0, location = 0;
	TYPE temp = 0;
	if (list->length == 0)
	{
		printf("当前系统中无数据，插入失败\n");
		system("pause");
		system("cls");
	}
	printf("请输入待插入数据的下标,范围为[0-%d]\n", (unsigned int)(list->length)-1);
	do
	{
		scanf("%d",&location);
		if (location < 0 || location >= list->length)printf("下标数据范围有误，请重新输入\n");
	} while (location < 0 || location >= list->length);
	if (list->length == list->List_Size)realloc(list->data, ((unsigned int)list->length + 1) * sizeof(TYPE));//若空间不足则重新申请空间
	temp = list->data[location];
	for ( i = list->length - 1; i >= location; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	printf("请输入插入数据的值，数据范围为正整数\n");
	do
	{
		scanf("%d", &list->data[location]);
		if (list->data[location] < 0)printf("输入的值有误，请重新输入\n");
	} while (list->data[location]< 0);
	list->length++;
	for (i = 0; i < list->length; i++) 
	{
		printf("%d\t", list->data[i]);
	}
	system("pause");
}
void Squence_List_Delect(Squence_List* list) 
{
	system("cls");
	int i = 0, location = 0;
	if (list->length == 0)
	{
		printf("当前系统中无数据，删除失败\n");
		system("pause");
		system("cls");
	}
	printf("请输入待删除数据的下标,范围为[0-%d]\n", (unsigned int)(list->length) - 1);
	do
	{
		scanf("%d", &location);
		if (location < 0 || location >= list->length)printf("下标数据范围有误，请重新输入\n");
	} while (location < 0 || location >= list->length);
	for (i = location; i < list->length; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->length--;
	for (i = 0; i < list->length; i++)
	{
		printf("%d\t", list->data[i]);
	}
	system("pause");
}
void Squence_List_Search(Squence_List* list) 
{
	system("cls");
	int i = 0, target_vaule = 0,num = 0;
	if (list->length == 0)
	{
		printf("当前系统中无数据，查找失败\n");
		system("pause");
		system("cls");
	}
	printf("请输入待查找数据的数值\n");
	do
	{
		scanf("%d", &target_vaule);
		if (target_vaule < 0)printf("数据范围有误，请重新输入\n");
	} while (target_vaule < 0);
	for (i = 0; i < list->length; i++)
	{
		if (target_vaule == list->data[i]) 
		{
			printf("数据匹配到下标为 %d 的元素符合条件\n",i);
			num++;
		}
	}
	if (num == 0)printf("没有匹配到数据\n");
	system("pause");
}
void Squence_List_Max_And_SecondaryMax(Squence_List *list) 
{
	system("cls");
	TYPE max_number = 0, max_number_secondary = 0;
	int location = 0, i = 0;
	max_number = Sort(list);
	Squence_List temp;
	for (i = 0; i < list->length; i++) 
	{
		if (list->data[i] == max_number)location = i;
	}
	Squence_List_Copy(list, &temp);//将原数组拷贝到temp中并删除原数组的最大值，再进行一次排序得到次最大值
	for (i = location; i < temp.length-1; i++) 
	{
		temp.data[i] = temp.data[i + 1];
	}
	max_number_secondary = Sort(&temp);
	printf("表中最大值为%d，次最大值为%d\n", max_number, max_number_secondary);
	system("pause");
}
void Squence_List_reset(Squence_List* list) 
{
	system("cls");
	int i = 0;
	for (i = 0; i < list->length; i++) list->data[i] = -1;
	printf("重置完成\n");
	system("pause");
}
int main() 
{
	char Select = '\0';
	int n = 0;
	Squence_List list;
	while (1) 
	{
		Menu_Output();
		setbuf(stdin, NULL);
		scanf("%c", &Select);
		switch (Select)
		{
		case 'a'://建立顺序表
			Squence_List_Create(&list);
			break;
		case 'b'://输出顺序表
			Squence_List_Display(&list);
			break;
		case 'c'://插入
			Squence_List_Insert(&list);
			break;
		case 'd'://删除
			Squence_List_Delect(&list);
			break;
		case 'e'://查询
			Squence_List_Search(&list);
			break;
		case 'f'://查询最大值及次大值
			Squence_List_Max_And_SecondaryMax(&list);
			break;
		case 'g'://重置表数据
			Squence_List_reset(&list);
			break;
		case 'n':
			goto while_end;
			break;
		default:
			break;
		}
	}
	while_end:
	return 0;
}
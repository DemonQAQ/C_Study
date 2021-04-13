
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1//栈最小容量
#define TYPE int

struct stack_array//数组栈
{
	int capacity;//栈容量
	int top_of_stack;//栈顶下标
	TYPE* array;//栈数组
};

struct stack_chained//链栈单个节点
{
	TYPE element;//存放栈元素
	stack_chained* next;
};

void menu_display() 
{
	printf("\t\t\t进制转换\n");
	printf("\t\ta.进制转换--数组栈\n");
	printf("\t\tb.进制转换--链栈\n");
	printf("\t\tn.退出\n");
	printf("\t\t输入字母选择功能(区分大小写)\n");
}

void scanf_reset(TYPE* value)//带范围检测的输入函数
{
	
	long double temp_value = 0;//临时变量储存输入的值
	do
	{
		fflush(stdin);
		setbuf(stdin, NULL);
		scanf("%lf", &temp_value);
		if (temp_value <= 0)printf("输入的数据值有误，请重新输入\n");
	} while (temp_value <= 0);//值符合范围通过
	*value = (TYPE)temp_value;//赋值到输入的变量
}

void error_output(int n) //指针检测
{
	if (n == 0) printf("遇到空指针错误\n");
	if (n == 1) printf("内存分配失败\n");
	if (n == 2) printf("当前栈满,入栈失败\n");
	if (n == 3) printf("当前栈空,出栈失败\n");
	system("pause");
	system("cls");
}

stack_array* arrayed_stack_create(stack_array* head)//建数组栈 
{
	system("cls");
	TYPE* array_temp = NULL;
	stack_array* head_temp = NULL;//临时指针储存头节点地址
	head_temp = head = (stack_array*)malloc(sizeof(stack_array));
	if (head_temp == NULL) //分配内存失败退出程序
	{
		error_output(1);//报错信息输出
		exit(-1);
	}

	head_temp->capacity = CAPACITY;//设置栈的容量
	array_temp = (TYPE*)malloc(sizeof(TYPE) * head->capacity);//根据容量分配数组
	if (array_temp == NULL) //分配内存失败退出程序
	{
		error_output(1);//报错信息输出
		exit(-1);
	}
	
	for (int i = 0; i < head->capacity; i++)//初始化栈内元素值
	{
		array_temp[i] = -1;
	}
	
	head->top_of_stack = -1;//初始化栈顶指针
	head->array = array_temp;//将数组连接到栈的数组指针
	return head;
}

stack_array* arrayed_push(stack_array* head , TYPE value)//数组栈 入栈 
{
	system("cls");
	if (head->top_of_stack >= head->capacity)//栈满则入栈失败 
	{
		error_output(2);
		exit(-1);
	}

	else 
	{
		head->array[++head->top_of_stack] = value;//把值入栈，栈顶指针自增1
	}
	return head;
}

TYPE arrayed_pop(stack_array* head) //数组栈 出栈
{
	system("cls");
	TYPE temp_value = 0;
	if (head->top_of_stack == -1)//栈空则出栈失败 
	{
		error_output(3);
		exit(-1);
	}

	temp_value = head->array[head->top_of_stack];//将栈顶元素的值赋值给变量
	head->array[head->top_of_stack--] = -1;//将栈顶元素的值置为-1，栈顶指针自减
	return temp_value;//返回取得的栈顶值
}

stack_chained* chained_stack_create(stack_chained* head)//建链栈
{
	system("cls");
	stack_chained* head_temp = NULL;
	if (head != NULL && head->element == -1)//如头指针不为空且元素值为-1则当前已有栈但未赋值，直接返回头指针
	{
		return head;
	}

	head_temp = (stack_chained*)malloc(sizeof(stack_chained));//创建一个链表节点
	if (head_temp == NULL) 
	{
		error_output(1);
		exit(-1);
	}

	//设定默认值
	head_temp->next = NULL;
	head_temp->element = -1;
	return head_temp;
}

stack_chained* chained_push(stack_chained* head , TYPE value)//链栈 入栈 
{
	system("cls");
	if (head->next == NULL && head->element == -1) //当前链表内有空的头结点，将值入头结点内
	{
		head->element = value;//将数据存入当前栈顶元素
	}
	else //新建结点入栈
	{
		stack_chained* new_temp = NULL;
		new_temp = (stack_chained*)malloc(sizeof(stack_chained));
		if (new_temp == NULL)
		{
			error_output(1);
			exit(-1);
		}

		//入栈操作，赋值，并把新节点插入在头节点前，让新节点作为头结点返回
		new_temp->element = value;
		new_temp->next = head;
		head = new_temp;
	}
	return head;
}


TYPE chained_pop(stack_chained** head)//链栈 出栈
{
	//需要返回栈顶的元素的值 和 头指针的值
	//栈顶元素的值通过函数返回，头指针的值通过传入二阶指针来修改值并返回
	system("cls");
	TYPE temp_value = 0;
	stack_chained* temp_pointer = *head;//临时指针，储存头结点的指针（二阶指针的解引用）
	if (temp_pointer->element == -1) 
	{
		error_output(3);
		exit(-1);
	}

	//读取栈顶元素的值
	temp_value = temp_pointer->element;
	*head = (*head)->next;
	return temp_value;
}

void convert(int flag)//进制转换 
{
	system("cls");
	int number = 0, cardinal_num = 0, temp = 0, i = 0, number_temp = 0;
	printf("请输入待转换的非负十进制整数\n");
	scanf_reset(&number);
	number_temp = number;
	printf("请输入转换的目标进制(2-9)\n");
	do
	{
		fflush(stdin);
		setbuf(stdin, NULL);
		scanf("%d", &cardinal_num);
		if (cardinal_num < 2 || cardinal_num > 9)printf("数据范围有误,请重新输入\n");
	} while (cardinal_num < 2 || cardinal_num > 9);
	int temp_array[128];
	for (i = 0; i < 128; i++)temp_array[i] = -1;
	if (flag == 1)//数组栈 
	{
		//建栈
		stack_array* head = NULL;
		head = arrayed_stack_create(head);
		if (&head == NULL)
		{
			error_output(0);
			exit(-1);
		}

		//进制转换，将number除以基数（cardinal_number）取余数，将余数入栈
		//反复求余直到余数为0结束
		//将栈内元素依次出栈到数组
		//数组内数据值即为对应进制的值
		
		//求余入栈
		while (number != 0)
		{
			temp = number % cardinal_num;
			number = number - temp;
			number = number / cardinal_num;
			arrayed_push(head, temp);
		}

		//将数据出栈到数组
		i = 0;
		while (head->top_of_stack > -1)
		{
			temp_array[i] = arrayed_pop(head);
			i++;
		}

		printf("输入的10进制数据为: %d\n", number_temp);
		printf("转换出的%d进制数据为: ", cardinal_num);
		i = 0;
		do
		{
			printf("%d", temp_array[i++]);
		} while (temp_array[i] != -1);
	}
	else //链栈
	{
		stack_chained* head = NULL ;
		head = chained_stack_create(head);
		if (&head == NULL)
		{
			error_output(0);
			exit(-1);
		}

		//同上
		while (number != 0)
		{
			temp = number % cardinal_num;
			number = number - temp;
			number = number / cardinal_num;
			head = chained_push(head, temp);
		}
		i = 0;
		while (head != NULL)
		{
			temp_array[i] = chained_pop(&head);
			i++;
		}

		printf("输入的10进制数据为: %d\n", number_temp);
		printf("转换出的%d进制数据为: ", cardinal_num);
		i = 0;
		do
		{
			printf("%d", temp_array[i++]);
		} while (temp_array[i] != -1);
	}
	printf("\n");
	system("pause");
}


int main() 
{
	char select = '0';
	while (1)
	{
		system("cls");
		menu_display();
		fflush(stdin);
		setbuf(stdin, NULL);
		scanf("%c", &select);
		fflush(stdin);
		setbuf(stdin, NULL);
		switch (select)
		{
		case 'a'://数组栈
			convert(1);
			break;
		case 'b'://链栈
			convert(0);
			break;
		case 'n':
			goto end;
			break;
		default:
			break;
		}
	}
	end:
	return 0;
}
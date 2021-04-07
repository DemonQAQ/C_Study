#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TYPE;

#define NUM 128//链表数据为字符时的数据长度

void Menu_Display()
{
	printf("\t\t\t\t\t链表\n");
	printf("\t\t\t输入字母选择功能(区分大小写):\n");
	printf("\t\t\ta.创建链表\n");
	printf("\t\t\tb.输出链表内数据\n");
	printf("\t\t\tc.在链表内插入节点\n");
	printf("\t\t\td.删除链表内节点\n");
	printf("\t\t\tn.退出\n");
}

struct Link_List //链表
{
	TYPE data;//数据
	Link_List* next;//尾指针
};

void error_information_output_number(int i)
{
	if (i == 1)printf("数据长度有误，请重新输入\n");
	if (i == 0)printf("遇到错误，空指针\n");
	system("pause");
	system("cls");
}

void LinkedList_scanf_overload(TYPE* data)//重载输入函数用于链表数据输入
{
	if (sizeof(TYPE) == sizeof(char)) //链表数据为字符类型时
	{
		char data_temp_char[NUM] = { 0 };
		do
		{
			printf("请输入数据，数据长度为%d字节\n", NUM);
			setbuf(stdin, NULL);
			scanf("%s", data_temp_char);
			if (strlen(data_temp_char) > NUM)error_information_output_number(1);
		} while (strlen(data_temp_char) > NUM);//判断输入的字符串长度是否超出数据范围
		strcpy((char*)data, data_temp_char);//把输入的值传给调用函数的变量
	}
	else
	{
		long double data_temp_num = 0;
		setbuf(stdin, NULL);
		scanf("%lf", &data_temp_num);//根据数据类型修改输入函数
		//输入数据范围检测
		*data = (TYPE)data_temp_num;
	}
}

struct Link_List* Link_lisk_create(struct Link_List* head)
{
	system("cls");
	int number = 0, i = 0;
	struct Link_List* p = NULL;
	if (head == NULL)
	{
		do
		{
			printf("请输入链表长度,数据范围为正整数,输入任意字母为0\n");
			setbuf(stdin, NULL);
			////while(getchar()!='\n');
			scanf("%d", &number);
			if (number < 0) error_information_output_number(1);
		} while (number < 0);
		if (number == 0)
		{
			printf("当前为空链表\n");
			system("pause");
			system("cls");
			goto end;
		}
		head = (struct Link_List*)malloc(sizeof(struct Link_List));//分配节点内存
		if (head == NULL) //内存分配检测
		{
			error_information_output_number(0);
			goto end;
		}
		p = head;
		for (i = 0; i < number; i++) //建表并输入数据
		{
			printf("请输入节点数据的值\n");
			LinkedList_scanf_overload(&p->data);//调用链表数据的专用输入函数
			if (i < number - 1)p->next = (struct Link_List*)malloc(sizeof(struct Link_List));
			if (i < number - 1)p = p->next;
			if (i == number - 1)p->next = NULL;//末节点的next指针置为空
		}
	}
	else
	{
		struct Link_List* head_temp = NULL;
		p = head;
		head_temp = Link_lisk_create(head_temp);
		while (p->next != NULL)p = p->next;
		p->next = head_temp;
		goto end;
	}

	printf("链表建立完成\n");
	system("pause");
	system("cls");
end:
	while (getchar() != '\n');
	return head;
}

struct Link_List* Link_list_display(struct Link_List* head)
{
	system("cls");
	struct Link_List* p = head;
	int i = 0;
	if (head == NULL)
	{
		error_information_output_number(0);
		goto end;
	}
	while (p != NULL)
	{
		printf("数据[%d] 值为%d\n", i, p->data);
		p = p->next;
		i++;
	}
	printf("输出完成\n");
	system("pause");
	system("cls");
end:
	return head;
}

struct Link_List* Link_list_insert(struct Link_List* head)
{
	system("cls");
	struct Link_List* p_temp = head;
	struct Link_List* p_new = NULL;
	int location = 0, list_length = 0, i = 0;
	char select = '\0';
	if (head == NULL)
	{
		printf("当前系统中无链表，请先建立链表\n");
		system("pause");
		head = Link_lisk_create(p_temp);
		if (head == NULL)
		{
			error_information_output_number(0);
			goto end;
		}
	}

	p_temp = head;
	printf("当前表内数据为：\n");
	while (p_temp != NULL)
	{
		printf("数据[%d] 值为%d\n", list_length, p_temp->data);
		p_temp = p_temp->next;
		list_length++;
	}

	printf("a.选定下标前插入元素\nb.选定下标后插入元素\n");
	printf("请选择插入模式(区分大小写)\n");
	setbuf(stdin, NULL);
	scanf("%c", &select);
	while (getchar() != '\n');

	p_temp = head;

	if (select == 'a')
	{
		printf("请选择插入位置的下标值，任意字符代表0号下标\n");
		do
		{
			setbuf(stdin, NULL);
			scanf("%d", &location);
			if (location < 0 || location >= list_length)printf("输入的值超出范围，请重新输入，范围为[0-%d]", list_length - 1);
		} while (location < 0 || location >= list_length);
		if (location == 0)
		{
			p_new = (struct Link_List*)malloc(sizeof(struct Link_List));
			if (p_new == NULL)
			{
				error_information_output_number(0);
				goto end;
			}
			printf("请输入插入节点数据的值,输入任意字符为0\n");
			LinkedList_scanf_overload(&p_new->data);
			p_new->next = head;
			head = p_new;
			printf("节点插入成功\n");
			system("pause");
			system("cls");
			goto end;
		}
		else
		{
			p_new = (struct Link_List*)malloc(sizeof(struct Link_List));
			if (p_new == NULL)
			{
				error_information_output_number(0);
				goto end;
			}
			for (i = 0; i < location - 1; i++)
			{
				p_temp = p_temp->next;
			}
			printf("请输入插入节点数据的值,输入任意字符为0\n");
			LinkedList_scanf_overload(&p_new->data);
			p_new->next = p_temp->next;
			p_temp->next = p_new;
			printf("节点插入成功\n");
			system("pause");
			system("cls");
			goto end;
		}
	}
	else if (select == 'b')
	{
		printf("请选择插入位置的下标值，任意字符代表0号下标\n");
		do
		{
			setbuf(stdin, NULL);
			scanf("%d", &location);
			if (location < 0 || location >= list_length)printf("输入的值超出范围，请重新输入，范围为[0-%d]", list_length - 1);
		} while (location < 0 || location >= list_length);
		for (i = 0; i < location; i++)
		{
			p_temp = p_temp->next;
		}
		p_new = (struct Link_List*)malloc(sizeof(struct Link_List));
		if (p_new == NULL)
		{
			error_information_output_number(0);
			goto end;
		}
		printf("请输入插入节点数据的值,输入任意字符为0\n");
		LinkedList_scanf_overload(&p_new->data);

		p_new->next = p_temp->next;
		p_temp->next = p_new;
		printf("节点插入成功\n");
		system("pause");
		system("cls");
		goto end;
	}
	else
	{
		printf("未选择模式,插入结束\n");
		system("pause");
		system("cls");
		return head;
	}
end:
	return head;
}

struct Link_List* Link_list_delect(struct Link_List* head)
{
	system("cls");
	struct Link_List* p_temp = head;
	struct Link_List* p_delect_temp = NULL;
	int list_length = 0, i = 0, delect_num_ = 0;
	TYPE delect_num = 0;
	char select = '0';
	bool flag = false;
	if (p_temp == NULL)
	{
		error_information_output_number(0);
		goto end;
	}

	do
	{
		p_temp = head;
		list_length = 0;
		printf("当前表内数据为：\n");
		while (p_temp != NULL)
		{
			printf("数据[%d] 值为%d\n", list_length, p_temp->data);
			p_temp = p_temp->next;
			list_length++;
		}
		printf("请输入删除的元素的下标,输入任意字符意为0,输入-1删除某一相同值的所有节点\n");
		setbuf(stdin, NULL);
		scanf("%d", &delect_num_);
		if (delect_num_ > list_length - 1 || delect_num_ < -1)
		{
			printf("输入的值有误，请重新输入，数据范围为[0-%d]\n", list_length - 1);
			system("pause");
			system("cls");
		}
	} while (delect_num_ > list_length - 1 || delect_num_ < -1);

	if (delect_num_ == -1)
	{
		p_temp = head;
		printf("请输入需要删除的值，任意字符代表0\n");
		setbuf(stdin, NULL);
		scanf("%d", &delect_num);
		while (p_temp != NULL)
		{
			if (p_temp->data == delect_num)
			{
				flag = true;
				break;
			}
			p_temp = p_temp->next;
		}
		if (flag == false)
		{
			printf("链表中没有查询到相应数值,删除完成\n");
			goto end;
		}
		list_length = 0;
		p_temp = head;
		while (p_temp != NULL)
		{
			if (p_temp->data == delect_num)
			{
				printf("查询到下标为 %d 的节点，数据为 %d\n", list_length, p_temp->data);
			}
			p_temp = p_temp->next;
			list_length++;
		}
		printf("输入Y/y确认删除，任意键退出\n");
		setbuf(stdin, NULL);
		scanf("%c", &select);
		if (select == 'y' || select == 'Y')
		{
			p_temp = head;
			while (p_temp != NULL)
			{
				if (head->data == delect_num)
				{
					p_delect_temp = p_temp;
					p_temp = p_temp->next;
					free(p_delect_temp);
					head = p_temp;
					if (head == NULL)break;
				}
				if (p_temp != head && p_temp->data == delect_num)
				{
					p_delect_temp->next = p_temp->next;
					free(p_temp);
					p_temp = p_delect_temp;
				}
				p_delect_temp = p_temp;
				p_temp = p_temp->next;
			}
			printf("删除完成\n");
		}
		else
		{
			printf("删除取消\n");
			system("pause");
			system("cls");
			goto end;
		}
	}
	else
	{
		p_temp = head;
		if (delect_num_ == 0)
		{
			p_delect_temp = head;
			head = head->next;
			free(p_delect_temp);
			p_temp = head;
		}
		else
		{
			for (i = 0; i < delect_num_ - 1; i++)
			{
				p_temp = p_temp->next;
			}
			p_delect_temp = p_temp;
			p_temp = p_temp->next;
			p_delect_temp->next = p_temp->next;
			free(p_temp);
		}
		printf("删除完成\n");
	}
	system("pause");
	system("cls");
end:
	while (getchar() != '\n');
	return head;
}

int main()
{
	struct Link_List* head = NULL;
	char select = '0';
	while (1)
	{
		system("cls");
		Menu_Display();
		setbuf(stdin, NULL);
		fflush(stdin);
		scanf("%c", &select);
		switch (select)
		{
		case 'a'://创建
			head = Link_lisk_create(head);
			break;
		case 'b'://输出
			head = Link_list_display(head);
			break;
		case 'c'://插入
			head = Link_list_insert(head);
			break;
		case 'd'://删除
			head = Link_list_delect(head);
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
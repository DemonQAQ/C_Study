#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line
{
	int major;//专业
	int number;//学号
	int phone_number;//电话
	char name[10];//姓名
	char address[60];//住址
	struct line* next;
};
struct line *AppendNode(struct line* head)
{
	struct line* p = NULL;
	struct line* p_head = head;
	char ch;
	p = (struct line*)malloc(sizeof(struct line));
	if (p == NULL) 
	{
		printf("分配空间失败\n");
		exit(0);
	}
	printf("链表/节点建立成功，请输入数据\n");
	printf("请输入专业，学号，电话\n");
	scanf("%d%d%d", &p->number,&p->major,&p->phone_number);
	while ((ch = getchar()) != '\n');
	printf("请输入姓名，住址\n");
	scanf("%10s", p->name);
	scanf("%6s", p->address);
	if (head == NULL) 
	{
		head = p;
		p->next = NULL;
	}
	else 
	{
		while (p_head->next != NULL) 
		{
			p_head = p_head->next;
		}
		p_head->next = p;
		p->next = NULL;
		printf("节点连接成功\n");
	}
	return head;
}
struct line *DisplayLink(struct line* head)
{
	struct line* p_head = head;
	if (head == NULL) 
	{
		return head;
	}
	printf("当前链表内数据：\n");
	int i=1;
	while (p_head != NULL)
	{
		printf("节点%d\n专业:%d\n学号:%d\n姓名:%s\n电话:%s\n住址:%d\n\n", i ,p_head->major,p_head->number, p_head->name, p_head->phone_number, p_head->address);
		p_head = p_head->next;
		i++;
	}
	return head;
}
struct line *deleteNode(struct line* head,int number)
{
	struct line* p = head;
	struct line* p_temp = NULL;
	if (head == NULL) 
	{
		return head;
	}
	while (p != NULL && p->number != number) 
	{
		p_temp = p;
		p = p->next;
	}
	if (p == NULL) 
	{
		p = p_temp;
	}
	if (p->number == number)
	{
		if (p == head)
		{
			head = p->next;
		}
		else
		{
			p_temp->next = p->next;
		}
		free(p);
	}
	else 
	{
		printf("链表中没有该节点\n");
	}
	return head;
}
struct line *insertNode(struct line* head,int number)
{
	struct line* p_temp = head;
	struct line* p = head;
	struct line* p_new = NULL;
	p_new = (struct line*)malloc(sizeof(struct line));
	if (p_new == NULL)
	{
		printf("分配内存失败\n");
		exit(0);
	}
	printf("请输入专业，学号，电话\n");
	scanf("%d%d%d", &p->number, &p->major, &p->phone_number);
	while ((ch = getchar()) != '\n');
	printf("请输入姓名，住址\n");
	scanf("%10s", p->name);
	scanf("%6s", p->address);
	p_new->next = NULL;
	if (head == NULL) 
	{
		head = p_new;
	}
	else
	{
		while (p->next != NULL && p->number != number)
		{
			printf("1");
			p_temp = p;
			p = p->next;
		}
		if (p->number = number)
		{
			if (p == head) 
			{
				printf("12");
				p_new->next = p->next;
				p->next = p_new;
			}
			else if (p->next == NULL) 
			{
				printf("14");
				p->next = p_new;
			}
			else
			{
				printf("输入a在节点前插入，输入b在节点后插入\n");
				int b;
				while ((b = getchar()) != 'a'|| (b = getchar()) != 'b');
				switch (b)
				{
				case 'a':
					p = p_temp;
					p_new->next = p->next;
					p->next = p_new;
					printf("15");
					break;
				case 'b':
					p_new->next = p->next;
					p->next = p_new;
					printf("13");
					break;
				}
			}
		}
	}
	return head;
}
int main()
{
	struct line* head = NULL;
	int number;
	char a,b,ch;
	printf("输入'a'创建新链表/节点\n输入's'显示当前链表内所有内容\n输入'd'进入链表节点删除\n输入'i'进入链表节点插入\n");
	lable1:
	printf("输入字符以选择功能\n");
	a = getchar();
	switch (a) 
	{
	case 'a':
		head = AppendNode(head);
		break;
	case 's': 
		if (head == NULL) 
		{
			printf("当前无链表\n");
			break;
		}
		DisplayLink(head);
		break;
	case 'd':
		printf("请输入学号\n");
		scanf("%d", &number);
		if (head == NULL)
		{
			printf("当前无链表\n");
			break;
		}
		head = deleteNode(head,number);
		break;
	case 'i':
		printf("请输入学号\n");
		scanf("%d", &number);
		head = insertNode(head, number);
		break;
	}
	printf("输入Y/y继续选择功能，任意键结束\n");
	setbuf(stdin, NULL);
	b = getchar();
	if (b == 'y' || b == 'Y') 
	{
		goto lable1;
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line
{
	int major;//רҵ
	int number;//ѧ��
	int phone_number;//�绰
	char name[10];//����
	char address[60];//סַ
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
		printf("����ռ�ʧ��\n");
		exit(0);
	}
	printf("����/�ڵ㽨���ɹ�������������\n");
	printf("������רҵ��ѧ�ţ��绰\n");
	scanf("%d%d%d", &p->number,&p->major,&p->phone_number);
	while ((ch = getchar()) != '\n');
	printf("������������סַ\n");
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
		printf("�ڵ����ӳɹ�\n");
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
	printf("��ǰ���������ݣ�\n");
	int i=1;
	while (p_head != NULL)
	{
		printf("�ڵ�%d\nרҵ:%d\nѧ��:%d\n����:%s\n�绰:%s\nסַ:%d\n\n", i ,p_head->major,p_head->number, p_head->name, p_head->phone_number, p_head->address);
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
		printf("������û�иýڵ�\n");
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
		printf("�����ڴ�ʧ��\n");
		exit(0);
	}
	printf("������רҵ��ѧ�ţ��绰\n");
	scanf("%d%d%d", &p->number, &p->major, &p->phone_number);
	while ((ch = getchar()) != '\n');
	printf("������������סַ\n");
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
				printf("����a�ڽڵ�ǰ���룬����b�ڽڵ�����\n");
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
	printf("����'a'����������/�ڵ�\n����'s'��ʾ��ǰ��������������\n����'d'��������ڵ�ɾ��\n����'i'��������ڵ����\n");
	lable1:
	printf("�����ַ���ѡ����\n");
	a = getchar();
	switch (a) 
	{
	case 'a':
		head = AppendNode(head);
		break;
	case 's': 
		if (head == NULL) 
		{
			printf("��ǰ������\n");
			break;
		}
		DisplayLink(head);
		break;
	case 'd':
		printf("������ѧ��\n");
		scanf("%d", &number);
		if (head == NULL)
		{
			printf("��ǰ������\n");
			break;
		}
		head = deleteNode(head,number);
		break;
	case 'i':
		printf("������ѧ��\n");
		scanf("%d", &number);
		head = insertNode(head, number);
		break;
	}
	printf("����Y/y����ѡ���ܣ����������\n");
	setbuf(stdin, NULL);
	b = getchar();
	if (b == 'y' || b == 'Y') 
	{
		goto lable1;
	}
	return 0;
}

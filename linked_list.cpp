#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TYPE;

#define NUM 128//��������Ϊ�ַ�ʱ�����ݳ���

void Menu_Display()
{
	printf("\t\t\t\t\t����\n");
	printf("\t\t\t������ĸѡ����(���ִ�Сд):\n");
	printf("\t\t\ta.��������\n");
	printf("\t\t\tb.�������������\n");
	printf("\t\t\tc.�������ڲ���ڵ�\n");
	printf("\t\t\td.ɾ�������ڽڵ�\n");
	printf("\t\t\tn.�˳�\n");
}

struct Link_List //����
{
	TYPE data;//����
	Link_List* next;//βָ��
};

void error_information_output_number(int i)
{
	if (i == 1)printf("���ݳ�����������������\n");
	if (i == 0)printf("�������󣬿�ָ��\n");
	system("pause");
	system("cls");
}

void LinkedList_scanf_overload(TYPE* data)//�������뺯������������������
{
	if (sizeof(TYPE) == sizeof(char)) //��������Ϊ�ַ�����ʱ
	{
		char data_temp_char[NUM] = { 0 };
		do
		{
			printf("���������ݣ����ݳ���Ϊ%d�ֽ�\n", NUM);
			setbuf(stdin, NULL);
			scanf("%s", data_temp_char);
			if (strlen(data_temp_char) > NUM)error_information_output_number(1);
		} while (strlen(data_temp_char) > NUM);//�ж�������ַ��������Ƿ񳬳����ݷ�Χ
		strcpy((char*)data, data_temp_char);//�������ֵ�������ú����ı���
	}
	else
	{
		long double data_temp_num = 0;
		setbuf(stdin, NULL);
		scanf("%lf", &data_temp_num);//�������������޸����뺯��
		//�������ݷ�Χ���
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
			printf("������������,���ݷ�ΧΪ������,����������ĸΪ0\n");
			setbuf(stdin, NULL);
			////while(getchar()!='\n');
			scanf("%d", &number);
			if (number < 0) error_information_output_number(1);
		} while (number < 0);
		if (number == 0)
		{
			printf("��ǰΪ������\n");
			system("pause");
			system("cls");
			goto end;
		}
		head = (struct Link_List*)malloc(sizeof(struct Link_List));//����ڵ��ڴ�
		if (head == NULL) //�ڴ������
		{
			error_information_output_number(0);
			goto end;
		}
		p = head;
		for (i = 0; i < number; i++) //������������
		{
			printf("������ڵ����ݵ�ֵ\n");
			LinkedList_scanf_overload(&p->data);//�����������ݵ�ר�����뺯��
			if (i < number - 1)p->next = (struct Link_List*)malloc(sizeof(struct Link_List));
			if (i < number - 1)p = p->next;
			if (i == number - 1)p->next = NULL;//ĩ�ڵ��nextָ����Ϊ��
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

	printf("���������\n");
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
		printf("����[%d] ֵΪ%d\n", i, p->data);
		p = p->next;
		i++;
	}
	printf("������\n");
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
		printf("��ǰϵͳ�����������Ƚ�������\n");
		system("pause");
		head = Link_lisk_create(p_temp);
		if (head == NULL)
		{
			error_information_output_number(0);
			goto end;
		}
	}

	p_temp = head;
	printf("��ǰ��������Ϊ��\n");
	while (p_temp != NULL)
	{
		printf("����[%d] ֵΪ%d\n", list_length, p_temp->data);
		p_temp = p_temp->next;
		list_length++;
	}

	printf("a.ѡ���±�ǰ����Ԫ��\nb.ѡ���±�����Ԫ��\n");
	printf("��ѡ�����ģʽ(���ִ�Сд)\n");
	setbuf(stdin, NULL);
	scanf("%c", &select);
	while (getchar() != '\n');

	p_temp = head;

	if (select == 'a')
	{
		printf("��ѡ�����λ�õ��±�ֵ�������ַ�����0���±�\n");
		do
		{
			setbuf(stdin, NULL);
			scanf("%d", &location);
			if (location < 0 || location >= list_length)printf("�����ֵ������Χ�����������룬��ΧΪ[0-%d]", list_length - 1);
		} while (location < 0 || location >= list_length);
		if (location == 0)
		{
			p_new = (struct Link_List*)malloc(sizeof(struct Link_List));
			if (p_new == NULL)
			{
				error_information_output_number(0);
				goto end;
			}
			printf("���������ڵ����ݵ�ֵ,���������ַ�Ϊ0\n");
			LinkedList_scanf_overload(&p_new->data);
			p_new->next = head;
			head = p_new;
			printf("�ڵ����ɹ�\n");
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
			printf("���������ڵ����ݵ�ֵ,���������ַ�Ϊ0\n");
			LinkedList_scanf_overload(&p_new->data);
			p_new->next = p_temp->next;
			p_temp->next = p_new;
			printf("�ڵ����ɹ�\n");
			system("pause");
			system("cls");
			goto end;
		}
	}
	else if (select == 'b')
	{
		printf("��ѡ�����λ�õ��±�ֵ�������ַ�����0���±�\n");
		do
		{
			setbuf(stdin, NULL);
			scanf("%d", &location);
			if (location < 0 || location >= list_length)printf("�����ֵ������Χ�����������룬��ΧΪ[0-%d]", list_length - 1);
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
		printf("���������ڵ����ݵ�ֵ,���������ַ�Ϊ0\n");
		LinkedList_scanf_overload(&p_new->data);

		p_new->next = p_temp->next;
		p_temp->next = p_new;
		printf("�ڵ����ɹ�\n");
		system("pause");
		system("cls");
		goto end;
	}
	else
	{
		printf("δѡ��ģʽ,�������\n");
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
		printf("��ǰ��������Ϊ��\n");
		while (p_temp != NULL)
		{
			printf("����[%d] ֵΪ%d\n", list_length, p_temp->data);
			p_temp = p_temp->next;
			list_length++;
		}
		printf("������ɾ����Ԫ�ص��±�,���������ַ���Ϊ0,����-1ɾ��ĳһ��ֵͬ�����нڵ�\n");
		setbuf(stdin, NULL);
		scanf("%d", &delect_num_);
		if (delect_num_ > list_length - 1 || delect_num_ < -1)
		{
			printf("�����ֵ�������������룬���ݷ�ΧΪ[0-%d]\n", list_length - 1);
			system("pause");
			system("cls");
		}
	} while (delect_num_ > list_length - 1 || delect_num_ < -1);

	if (delect_num_ == -1)
	{
		p_temp = head;
		printf("��������Ҫɾ����ֵ�������ַ�����0\n");
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
			printf("������û�в�ѯ����Ӧ��ֵ,ɾ�����\n");
			goto end;
		}
		list_length = 0;
		p_temp = head;
		while (p_temp != NULL)
		{
			if (p_temp->data == delect_num)
			{
				printf("��ѯ���±�Ϊ %d �Ľڵ㣬����Ϊ %d\n", list_length, p_temp->data);
			}
			p_temp = p_temp->next;
			list_length++;
		}
		printf("����Y/yȷ��ɾ����������˳�\n");
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
			printf("ɾ�����\n");
		}
		else
		{
			printf("ɾ��ȡ��\n");
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
		printf("ɾ�����\n");
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
		case 'a'://����
			head = Link_lisk_create(head);
			break;
		case 'b'://���
			head = Link_list_display(head);
			break;
		case 'c'://����
			head = Link_list_insert(head);
			break;
		case 'd'://ɾ��
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
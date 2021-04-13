
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1//ջ��С����
#define TYPE int

struct stack_array//����ջ
{
	int capacity;//ջ����
	int top_of_stack;//ջ���±�
	TYPE* array;//ջ����
};

struct stack_chained//��ջ�����ڵ�
{
	TYPE element;//���ջԪ��
	stack_chained* next;
};

void menu_display() 
{
	printf("\t\t\t����ת��\n");
	printf("\t\ta.����ת��--����ջ\n");
	printf("\t\tb.����ת��--��ջ\n");
	printf("\t\tn.�˳�\n");
	printf("\t\t������ĸѡ����(���ִ�Сд)\n");
}

void scanf_reset(TYPE* value)//����Χ�������뺯��
{
	
	long double temp_value = 0;//��ʱ�������������ֵ
	do
	{
		fflush(stdin);
		setbuf(stdin, NULL);
		scanf("%lf", &temp_value);
		if (temp_value <= 0)printf("���������ֵ��������������\n");
	} while (temp_value <= 0);//ֵ���Ϸ�Χͨ��
	*value = (TYPE)temp_value;//��ֵ������ı���
}

void error_output(int n) //ָ����
{
	if (n == 0) printf("������ָ�����\n");
	if (n == 1) printf("�ڴ����ʧ��\n");
	if (n == 2) printf("��ǰջ��,��ջʧ��\n");
	if (n == 3) printf("��ǰջ��,��ջʧ��\n");
	system("pause");
	system("cls");
}

stack_array* arrayed_stack_create(stack_array* head)//������ջ 
{
	system("cls");
	TYPE* array_temp = NULL;
	stack_array* head_temp = NULL;//��ʱָ�봢��ͷ�ڵ��ַ
	head_temp = head = (stack_array*)malloc(sizeof(stack_array));
	if (head_temp == NULL) //�����ڴ�ʧ���˳�����
	{
		error_output(1);//������Ϣ���
		exit(-1);
	}

	head_temp->capacity = CAPACITY;//����ջ������
	array_temp = (TYPE*)malloc(sizeof(TYPE) * head->capacity);//����������������
	if (array_temp == NULL) //�����ڴ�ʧ���˳�����
	{
		error_output(1);//������Ϣ���
		exit(-1);
	}
	
	for (int i = 0; i < head->capacity; i++)//��ʼ��ջ��Ԫ��ֵ
	{
		array_temp[i] = -1;
	}
	
	head->top_of_stack = -1;//��ʼ��ջ��ָ��
	head->array = array_temp;//���������ӵ�ջ������ָ��
	return head;
}

stack_array* arrayed_push(stack_array* head , TYPE value)//����ջ ��ջ 
{
	system("cls");
	if (head->top_of_stack >= head->capacity)//ջ������ջʧ�� 
	{
		error_output(2);
		exit(-1);
	}

	else 
	{
		head->array[++head->top_of_stack] = value;//��ֵ��ջ��ջ��ָ������1
	}
	return head;
}

TYPE arrayed_pop(stack_array* head) //����ջ ��ջ
{
	system("cls");
	TYPE temp_value = 0;
	if (head->top_of_stack == -1)//ջ�����ջʧ�� 
	{
		error_output(3);
		exit(-1);
	}

	temp_value = head->array[head->top_of_stack];//��ջ��Ԫ�ص�ֵ��ֵ������
	head->array[head->top_of_stack--] = -1;//��ջ��Ԫ�ص�ֵ��Ϊ-1��ջ��ָ���Լ�
	return temp_value;//����ȡ�õ�ջ��ֵ
}

stack_chained* chained_stack_create(stack_chained* head)//����ջ
{
	system("cls");
	stack_chained* head_temp = NULL;
	if (head != NULL && head->element == -1)//��ͷָ�벻Ϊ����Ԫ��ֵΪ-1��ǰ����ջ��δ��ֵ��ֱ�ӷ���ͷָ��
	{
		return head;
	}

	head_temp = (stack_chained*)malloc(sizeof(stack_chained));//����һ������ڵ�
	if (head_temp == NULL) 
	{
		error_output(1);
		exit(-1);
	}

	//�趨Ĭ��ֵ
	head_temp->next = NULL;
	head_temp->element = -1;
	return head_temp;
}

stack_chained* chained_push(stack_chained* head , TYPE value)//��ջ ��ջ 
{
	system("cls");
	if (head->next == NULL && head->element == -1) //��ǰ�������пյ�ͷ��㣬��ֵ��ͷ�����
	{
		head->element = value;//�����ݴ��뵱ǰջ��Ԫ��
	}
	else //�½������ջ
	{
		stack_chained* new_temp = NULL;
		new_temp = (stack_chained*)malloc(sizeof(stack_chained));
		if (new_temp == NULL)
		{
			error_output(1);
			exit(-1);
		}

		//��ջ��������ֵ�������½ڵ������ͷ�ڵ�ǰ�����½ڵ���Ϊͷ��㷵��
		new_temp->element = value;
		new_temp->next = head;
		head = new_temp;
	}
	return head;
}


TYPE chained_pop(stack_chained** head)//��ջ ��ջ
{
	//��Ҫ����ջ����Ԫ�ص�ֵ �� ͷָ���ֵ
	//ջ��Ԫ�ص�ֵͨ���������أ�ͷָ���ֵͨ���������ָ�����޸�ֵ������
	system("cls");
	TYPE temp_value = 0;
	stack_chained* temp_pointer = *head;//��ʱָ�룬����ͷ����ָ�루����ָ��Ľ����ã�
	if (temp_pointer->element == -1) 
	{
		error_output(3);
		exit(-1);
	}

	//��ȡջ��Ԫ�ص�ֵ
	temp_value = temp_pointer->element;
	*head = (*head)->next;
	return temp_value;
}

void convert(int flag)//����ת�� 
{
	system("cls");
	int number = 0, cardinal_num = 0, temp = 0, i = 0, number_temp = 0;
	printf("�������ת���ķǸ�ʮ��������\n");
	scanf_reset(&number);
	number_temp = number;
	printf("������ת����Ŀ�����(2-9)\n");
	do
	{
		fflush(stdin);
		setbuf(stdin, NULL);
		scanf("%d", &cardinal_num);
		if (cardinal_num < 2 || cardinal_num > 9)printf("���ݷ�Χ����,����������\n");
	} while (cardinal_num < 2 || cardinal_num > 9);
	int temp_array[128];
	for (i = 0; i < 128; i++)temp_array[i] = -1;
	if (flag == 1)//����ջ 
	{
		//��ջ
		stack_array* head = NULL;
		head = arrayed_stack_create(head);
		if (&head == NULL)
		{
			error_output(0);
			exit(-1);
		}

		//����ת������number���Ի�����cardinal_number��ȡ��������������ջ
		//��������ֱ������Ϊ0����
		//��ջ��Ԫ�����γ�ջ������
		//����������ֵ��Ϊ��Ӧ���Ƶ�ֵ
		
		//������ջ
		while (number != 0)
		{
			temp = number % cardinal_num;
			number = number - temp;
			number = number / cardinal_num;
			arrayed_push(head, temp);
		}

		//�����ݳ�ջ������
		i = 0;
		while (head->top_of_stack > -1)
		{
			temp_array[i] = arrayed_pop(head);
			i++;
		}

		printf("�����10��������Ϊ: %d\n", number_temp);
		printf("ת������%d��������Ϊ: ", cardinal_num);
		i = 0;
		do
		{
			printf("%d", temp_array[i++]);
		} while (temp_array[i] != -1);
	}
	else //��ջ
	{
		stack_chained* head = NULL ;
		head = chained_stack_create(head);
		if (&head == NULL)
		{
			error_output(0);
			exit(-1);
		}

		//ͬ��
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

		printf("�����10��������Ϊ: %d\n", number_temp);
		printf("ת������%d��������Ϊ: ", cardinal_num);
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
		case 'a'://����ջ
			convert(1);
			break;
		case 'b'://��ջ
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
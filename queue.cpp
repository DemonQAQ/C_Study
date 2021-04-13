
#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#define capacity 5//ʵ������+1 ����5����г�Ϊ4
#define MAX_EDGE 25565
#define MIN_EDGE 0

struct queue_array //����_����
{
	TYPE* array;
	int rear;//��β
	int head;//��ͷ
	int length;
};

struct queue_chained //����_����
{
	TYPE element;
	queue_chained* next;
};

void menu_display(int flag)//�˵�
{
	system("cls");
	if (flag == -1)printf("\t\t\t����(δѡ��ģʽ)\n");
	if (flag == 0)printf("\t\t\t����(���鴢��ģʽ)\n");
	if (flag == 1)printf("\t\t\t����(������ģʽ)\n");
	printf("\t\ta.��������\n");
	printf("\t\tb.���\n");
	printf("\t\tc.����\n");
	printf("\t\tn.�˳�\n");
	printf("��������ĸѡ����(���ִ�Сд):\n");
}

void information_output(int flag)//��ʾ��Ϣ���
{
	if (flag == 0)printf("���д����ɹ�\n");
	if (flag == 1)printf("��ӳɹ�\n");
	if (flag == 2)printf("��ǰ���������ʧ��\n");
	if (flag == 3)printf("���ӳɹ�\n");
	if (flag == 4)printf("��ǰ�ӿգ�����ʧ��\n");
	if (flag == 5)printf("�ڴ����ʧ��\n");
	if (flag == 6)printf("��ǰϵͳ���޶���\n");
	system("pause");
	system("cls");
}

int scanf_overload(TYPE* value, long double min_edge, long double max_edge)//�������ֵ��������Ͻ���½�
{
	if (min_edge >= max_edge)
	{
		printf("�½�ֵ���ڻ�����Ͻ�ֵ\n");
		return 0;
	}
	long double value_temp = 0;
	int flag = -1;//�ж���������������Ƿ����
	do
	{
		value_temp = 0;
		flag = scanf("%lf", &value_temp);//�����ֵΪ�ַ�����scanf�ĺ�������ֵΪ0
		if (!flag)//flagΪ0��Ϊ�����������ʹ���
		{
			printf("�����ֵ���Ͳ�����\n");
			value_temp = (min_edge + max_edge) / 2;//����ֵ��Χ�ж�
		}
		if (value_temp > max_edge || value_temp < min_edge)printf("�����ֵ������Χ\n");//������ȷʱ�ж����ݷ�Χ�Ƿ�Խ��
		while (getchar() != '\n');
	} while (value_temp > max_edge || value_temp < min_edge || flag == 0);
	*value = (TYPE)value_temp;
	return 1;
}

queue_array* queue_array_create()//������д���
{
	queue_array* head_temp = NULL;
	TYPE* array_temp = NULL;
	int i = 0;
	head_temp = (queue_array*)malloc(sizeof(queue_array));
	if (head_temp == NULL)exit(-1);
	else head_temp->length = capacity;
	array_temp = (TYPE*)malloc((sizeof(TYPE) * head_temp->length));//��������ڴ�ռ�
	if (array_temp == NULL)exit(-1);

	//��ʼ������ֵ
	head_temp->array = array_temp;
	for (i = 0; i < head_temp->length; i++)
	{
		array_temp[i] = -1;//����ֵ��ʼ��
	}
	head_temp->rear = 0;
	head_temp->head = 0;

	information_output(0);//���д����ɹ�
	return head_temp;
}

queue_array* queue_array_enqueue(queue_array* head)//���
{
	TYPE value = 0;
	//���������: ��ͷ��0���±�,��β��length-1�� ����ͷ��x���±꣬��β��x-1��
	if (head->head == 0 && head->rear == head->length - 1 || head->rear == (head->head - 1))
	{
		information_output(2);//�������ʧ��
	}
	else
	{
		printf("���������ӵ�ֵ\n");
		scanf_overload(&value, MIN_EDGE, MAX_EDGE);
		head->array[head->rear] = value;
		head->rear++;
		//��βָ��ָ��length-1�±겢��ͷָ�����0 ��βָ��ѭ��
		if (head->rear == head->length - 1 && head->head > 0)head->rear = 0;//βָ��ѭ��
		information_output(1);//��ӳɹ�
	}
	return head;
}

TYPE queue_array_dequeue(queue_array** head) //����
{
	queue_array* head_temp = *head;
	TYPE value_temp = 0;
	if (head_temp->head != head_temp->rear) //��Ϊ�ն���ʱ
	{
		value_temp = head_temp->array[head_temp->head];//����
		head_temp->array[head_temp->head] = -1;//����ֵ
		//ͷָ����βָ�����ʱ����ͷָ�뵽��βʱ��ͷָ��ֵָ���ͷ����ѭ������
		if (head_temp->head > head_temp->rear && head_temp->head == head_temp->length - 2)head_temp->head = 0;
		//ͷָ�����
		else head_temp->head++;
		//ͷָ�����βָ��ʱ�ն�������ֵ
		if (head_temp->head == head_temp->rear)
		{
			head_temp->head = 0;
			head_temp->rear = 0;
		}
		printf("ȡ��ֵΪ:%d\n", value_temp);
		information_output(3); //���ӳɹ�
		return value_temp;
	}
	else
	{
		information_output(4);//�ӿճ���ʧ��
		return -1;
	}
}

queue_chained* queue_chained_create(queue_chained** rear)//�����д���
{
	//����βָ�����ڴ������ĩβ�ڵ��λ��
	queue_chained* head_temp = NULL;
	head_temp = (queue_chained*)malloc(sizeof(queue_chained));
	if (head_temp == NULL)
	{
		information_output(5);
		return NULL;
	}
	//ͷ����ʼ��
	head_temp->next = NULL;
	head_temp->element = -1;
	*rear = head_temp->next;//βָ��ָ������ĩβ�ڵ�
	information_output(0);
	return head_temp;
}

queue_chained* queue_chained_enqueue(queue_chained* head, queue_chained* rear)//���������
{

	queue_chained* head_new = NULL;
	queue_chained* rear_temp = rear;//�ݴ�βָ��
	head_new = (queue_chained*)malloc(sizeof(queue_chained));//�½ڵ㴴��
	TYPE value = 0;
	if (head == NULL || head_new == NULL)
	{
		information_output(6);
		return NULL;
	}
	//�������ݲ����
	printf("��������ӵ�Ԫ��ֵ\n");
	scanf_overload(&value, MIN_EDGE, MAX_EDGE);
	head_new->element = value;
	head_new->next = NULL;
	if (head->next == NULL)//�����ǰ�ӿգ����½ڵ����ͷ����
	{
		head->next = head_new;
		rear_temp = head_new;//��β���ָ������ĩβ�ڵ�
	}
	else//�����½ڵ��������ĩβ�ڵ�
	{
		rear_temp->next = head_new;
		rear_temp = head_new;//�ƶ�βָ�뵽�µ�ĩβ�ڵ�
	}
	information_output(1);
	return rear_temp;//������β���
}

TYPE queue_chained_dequeue(queue_chained* head)//�����г���
{
	queue_chained* temp = NULL;
	TYPE value = 0;
	if (head == NULL)//δ��������
	{
		information_output(6);
		return NULL;
	}
	if (head->next == NULL)//�ն���
	{
		information_output(4);
		return -1;
	}

	temp = head->next;//�������ӵ�λ���ݴ�
	value = temp->element;//����
	head->next = head->next->next;//ɾ��ͷ���
	temp->next = NULL;
	free(temp);
	printf("%d\n", value);
	information_output(3);
	return value;
}

int main()
{
	char select = 0;
	int flag = -1;
	//������б���
	queue_array* head_a = NULL;
	//-------------------------
	//�����б���
	queue_chained* head_c = NULL;
	queue_chained* rear_c = NULL;
	//-------------------------
	while (1)
	{
		menu_display(flag);
		scanf("%c", &select);
		while (getchar() != '\n');
		switch (select)
		{
		case 'a'://��������
			if (flag == -1)
			{
				printf("����������ѡ��ģʽ:\n0.���鴢��ģʽ\n1.������ģʽ\n");
				scanf_overload(&flag, 0, 1);
			}
			else
			{
				printf("���ж���\n");
				system("pause");
				break;
			}
			if (flag == 0)head_a = queue_array_create();
			if (flag == 1)head_c = queue_chained_create(&rear_c);
			break;
		case 'b'://���
			if (flag == -1)
			{
				printf("δ��������,���ȴ�������\n");
				system("pause");
				break;
			}
			if (flag == 0)head_a = queue_array_enqueue(head_a);
			if (flag == 1)rear_c = queue_chained_enqueue(head_c, rear_c);
			break;
		case 'c'://����
			if (flag == -1)
			{
				printf("δ��������,���ȴ�������\n");
				system("pause");
				break;
			}
			if (flag == 0)queue_array_dequeue(&head_a);
			if (flag == 1)queue_chained_dequeue(head_c);
			break;
		case 'n'://����
			goto end;
			break;
		default:
			break;
		};
	}
end:
	return 0;
}
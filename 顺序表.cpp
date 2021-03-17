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
void Squence_List_Copy(Squence_List* list1, Squence_List* list2)//1Ϊԭ����2ΪĿ�����
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
	if (list2->length != list1->length) exit(-5);//�������鳤�Ȳ�ƥ������ʧ��
}
void Menu_Output() 
{
	system("cls");
	printf("\t\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\t\t\t˳���\n");
	printf("\t\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\t\t����'a'����˳���\n");
	printf("\t\t\t\t\t\t����'b'�����ĸ���Ԫ���Լ���Ӧ���±�\n");
	printf("\t\t\t\t\t\t����'c'�ڱ��в���Ԫ��\n");
	printf("\t\t\t\t\t\t����'d'ɾ������ĳԪ��\n");
	printf("\t\t\t\t\t\t����'e'���ұ���ĳԪ��\n");
	printf("\t\t\t\t\t\t����'f'����������ֵ�ʹ����ֵ\n");
	printf("\t\t\t\t\t\t����'g'��ʼ����\n");
	printf("\t\t\t\t\t\t����'n'�˳�ϵͳ\n");

}
void Squence_List_Input(Squence_List* list)
{
	int Input_Number = 0, i = 0;
	if (list == NULL)exit(-1);
	printf("�밴��˳����������,������������������س�����ɱ���һ��Ԫ�ص����룬����-1��������\n");
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
		printf("������ʧ��\n");
		system("pause");
		system("cls");
	}
	do
	{
		printf("���������0��������\n");
		setbuf(stdin, NULL);
		scanf("%d", &length_i);
		if (length_i <= 0)
		{
			printf("������������,���������0��������\n");
			system("pause");
			system("cls");
		}
	} while (length_i <= 0 );
	list->List_Size = length_i;
	list->length = 0;
	list->data = (TYPE*)malloc(sizeof(TYPE)*length_i);
	if (list->data == NULL)exit(-3);
	Squence_List_Input(list);//Ϊ����������
	printf("�������,��������ز˵�\n");
	system("pause");
	system("cls");
	return list;
}
void Squence_List_Display(Squence_List* list) 
{
	system("cls");
	if (list->length == 0 || list->data[0] == -1)
	{
		printf("��ǰϵͳ�������ݣ����ʧ��\n");
		system("pause");
		system("cls");
	}
	int i = 0;
	for(i=0;i< list->List_Size;i++)
	{
		if (list->data[i] == -1)break;
		printf("�±�:%d ��ֵ:%d\n",i,list->data[i]);
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
		printf("��ǰϵͳ�������ݣ�����ʧ��\n");
		system("pause");
		system("cls");
	}
	printf("��������������ݵ��±�,��ΧΪ[0-%d]\n", (unsigned int)(list->length)-1);
	do
	{
		scanf("%d",&location);
		if (location < 0 || location >= list->length)printf("�±����ݷ�Χ��������������\n");
	} while (location < 0 || location >= list->length);
	if (list->length == list->List_Size)realloc(list->data, ((unsigned int)list->length + 1) * sizeof(TYPE));//���ռ䲻������������ռ�
	temp = list->data[location];
	for ( i = list->length - 1; i >= location; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	printf("������������ݵ�ֵ�����ݷ�ΧΪ������\n");
	do
	{
		scanf("%d", &list->data[location]);
		if (list->data[location] < 0)printf("�����ֵ��������������\n");
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
		printf("��ǰϵͳ�������ݣ�ɾ��ʧ��\n");
		system("pause");
		system("cls");
	}
	printf("�������ɾ�����ݵ��±�,��ΧΪ[0-%d]\n", (unsigned int)(list->length) - 1);
	do
	{
		scanf("%d", &location);
		if (location < 0 || location >= list->length)printf("�±����ݷ�Χ��������������\n");
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
		printf("��ǰϵͳ�������ݣ�����ʧ��\n");
		system("pause");
		system("cls");
	}
	printf("��������������ݵ���ֵ\n");
	do
	{
		scanf("%d", &target_vaule);
		if (target_vaule < 0)printf("���ݷ�Χ��������������\n");
	} while (target_vaule < 0);
	for (i = 0; i < list->length; i++)
	{
		if (target_vaule == list->data[i]) 
		{
			printf("����ƥ�䵽�±�Ϊ %d ��Ԫ�ط�������\n",i);
			num++;
		}
	}
	if (num == 0)printf("û��ƥ�䵽����\n");
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
	Squence_List_Copy(list, &temp);//��ԭ���鿽����temp�в�ɾ��ԭ��������ֵ���ٽ���һ������õ������ֵ
	for (i = location; i < temp.length-1; i++) 
	{
		temp.data[i] = temp.data[i + 1];
	}
	max_number_secondary = Sort(&temp);
	printf("�������ֵΪ%d�������ֵΪ%d\n", max_number, max_number_secondary);
	system("pause");
}
void Squence_List_reset(Squence_List* list) 
{
	system("cls");
	int i = 0;
	for (i = 0; i < list->length; i++) list->data[i] = -1;
	printf("�������\n");
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
		case 'a'://����˳���
			Squence_List_Create(&list);
			break;
		case 'b'://���˳���
			Squence_List_Display(&list);
			break;
		case 'c'://����
			Squence_List_Insert(&list);
			break;
		case 'd'://ɾ��
			Squence_List_Delect(&list);
			break;
		case 'e'://��ѯ
			Squence_List_Search(&list);
			break;
		case 'f'://��ѯ���ֵ���δ�ֵ
			Squence_List_Max_And_SecondaryMax(&list);
			break;
		case 'g'://���ñ�����
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
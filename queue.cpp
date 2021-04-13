
#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#define capacity 5//实际容量+1 输入5则队列长为4
#define MAX_EDGE 25565
#define MIN_EDGE 0

struct queue_array //数组_队列
{
	TYPE* array;
	int rear;//队尾
	int head;//队头
	int length;
};

struct queue_chained //链表_队列
{
	TYPE element;
	queue_chained* next;
};

void menu_display(int flag)//菜单
{
	system("cls");
	if (flag == -1)printf("\t\t\t队列(未选择模式)\n");
	if (flag == 0)printf("\t\t\t队列(数组储存模式)\n");
	if (flag == 1)printf("\t\t\t队列(链表储存模式)\n");
	printf("\t\ta.创建队列\n");
	printf("\t\tb.入队\n");
	printf("\t\tc.出队\n");
	printf("\t\tn.退出\n");
	printf("请输入字母选择功能(区分大小写):\n");
}

void information_output(int flag)//提示信息输出
{
	if (flag == 0)printf("队列创建成功\n");
	if (flag == 1)printf("入队成功\n");
	if (flag == 2)printf("当前队满，入队失败\n");
	if (flag == 3)printf("出队成功\n");
	if (flag == 4)printf("当前队空，出队失败\n");
	if (flag == 5)printf("内存分配失败\n");
	if (flag == 6)printf("当前系统内无队列\n");
	system("pause");
	system("cls");
}

int scanf_overload(TYPE* value, long double min_edge, long double max_edge)//待输入的值，输入的上界和下界
{
	if (min_edge >= max_edge)
	{
		printf("下界值大于或等于上界值\n");
		return 0;
	}
	long double value_temp = 0;
	int flag = -1;//判断输入的数据类型是否符合
	do
	{
		value_temp = 0;
		flag = scanf("%lf", &value_temp);//输入的值为字符串则scanf的函数返回值为0
		if (!flag)//flag为0则为输入数据类型错误
		{
			printf("输入的值类型不符合\n");
			value_temp = (min_edge + max_edge) / 2;//跳过值范围判断
		}
		if (value_temp > max_edge || value_temp < min_edge)printf("输入的值超出范围\n");//类型正确时判断数据范围是否越界
		while (getchar() != '\n');
	} while (value_temp > max_edge || value_temp < min_edge || flag == 0);
	*value = (TYPE)value_temp;
	return 1;
}

queue_array* queue_array_create()//数组队列创建
{
	queue_array* head_temp = NULL;
	TYPE* array_temp = NULL;
	int i = 0;
	head_temp = (queue_array*)malloc(sizeof(queue_array));
	if (head_temp == NULL)exit(-1);
	else head_temp->length = capacity;
	array_temp = (TYPE*)malloc((sizeof(TYPE) * head_temp->length));//分配队列内存空间
	if (array_temp == NULL)exit(-1);

	//初始化队列值
	head_temp->array = array_temp;
	for (i = 0; i < head_temp->length; i++)
	{
		array_temp[i] = -1;//队列值初始化
	}
	head_temp->rear = 0;
	head_temp->head = 0;

	information_output(0);//队列创建成功
	return head_temp;
}

queue_array* queue_array_enqueue(queue_array* head)//入队
{
	TYPE value = 0;
	//队满的情况: 队头在0号下标,队尾在length-1处 ；队头在x号下标，队尾在x-1处
	if (head->head == 0 && head->rear == head->length - 1 || head->rear == (head->head - 1))
	{
		information_output(2);//队满入队失败
	}
	else
	{
		printf("请输入待入队的值\n");
		scanf_overload(&value, MIN_EDGE, MAX_EDGE);
		head->array[head->rear] = value;
		head->rear++;
		//当尾指针指向length-1下标并且头指针大于0 将尾指针循环
		if (head->rear == head->length - 1 && head->head > 0)head->rear = 0;//尾指针循环
		information_output(1);//入队成功
	}
	return head;
}

TYPE queue_array_dequeue(queue_array** head) //出队
{
	queue_array* head_temp = *head;
	TYPE value_temp = 0;
	if (head_temp->head != head_temp->rear) //不为空队列时
	{
		value_temp = head_temp->array[head_temp->head];//出队
		head_temp->array[head_temp->head] = -1;//重置值
		//头指针在尾指针后面时，则头指针到队尾时让头指针值指向队头，做循环数组
		if (head_temp->head > head_temp->rear && head_temp->head == head_temp->length - 2)head_temp->head = 0;
		//头指针后移
		else head_temp->head++;
		//头指针等于尾指针时空队列重置值
		if (head_temp->head == head_temp->rear)
		{
			head_temp->head = 0;
			head_temp->rear = 0;
		}
		printf("取得值为:%d\n", value_temp);
		information_output(3); //出队成功
		return value_temp;
	}
	else
	{
		information_output(4);//队空出队失败
		return -1;
	}
}

queue_chained* queue_chained_create(queue_chained** rear)//链队列创建
{
	//二阶尾指针用于存放链表末尾节点的位置
	queue_chained* head_temp = NULL;
	head_temp = (queue_chained*)malloc(sizeof(queue_chained));
	if (head_temp == NULL)
	{
		information_output(5);
		return NULL;
	}
	//头结点初始化
	head_temp->next = NULL;
	head_temp->element = -1;
	*rear = head_temp->next;//尾指针指向链表末尾节点
	information_output(0);
	return head_temp;
}

queue_chained* queue_chained_enqueue(queue_chained* head, queue_chained* rear)//链队列入队
{

	queue_chained* head_new = NULL;
	queue_chained* rear_temp = rear;//暂存尾指针
	head_new = (queue_chained*)malloc(sizeof(queue_chained));//新节点创建
	TYPE value = 0;
	if (head == NULL || head_new == NULL)
	{
		information_output(6);
		return NULL;
	}
	//输入数据并入队
	printf("请输入入队的元素值\n");
	scanf_overload(&value, MIN_EDGE, MAX_EDGE);
	head_new->element = value;
	head_new->next = NULL;
	if (head->next == NULL)//如果当前队空，将新节点接在头结点后
	{
		head->next = head_new;
		rear_temp = head_new;//将尾结点指向链表末尾节点
	}
	else//否则将新节点接在链表末尾节点
	{
		rear_temp->next = head_new;
		rear_temp = head_new;//移动尾指针到新的末尾节点
	}
	information_output(1);
	return rear_temp;//返回新尾结点
}

TYPE queue_chained_dequeue(queue_chained* head)//链队列出队
{
	queue_chained* temp = NULL;
	TYPE value = 0;
	if (head == NULL)//未创建队列
	{
		information_output(6);
		return NULL;
	}
	if (head->next == NULL)//空队列
	{
		information_output(4);
		return -1;
	}

	temp = head->next;//将待出队的位置暂存
	value = temp->element;//出队
	head->next = head->next->next;//删除头结点
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
	//数组队列变量
	queue_array* head_a = NULL;
	//-------------------------
	//链队列变量
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
		case 'a'://创建队列
			if (flag == -1)
			{
				printf("请输入数字选择模式:\n0.数组储存模式\n1.链表储存模式\n");
				scanf_overload(&flag, 0, 1);
			}
			else
			{
				printf("已有队列\n");
				system("pause");
				break;
			}
			if (flag == 0)head_a = queue_array_create();
			if (flag == 1)head_c = queue_chained_create(&rear_c);
			break;
		case 'b'://入队
			if (flag == -1)
			{
				printf("未创建数组,请先创建队列\n");
				system("pause");
				break;
			}
			if (flag == 0)head_a = queue_array_enqueue(head_a);
			if (flag == 1)rear_c = queue_chained_enqueue(head_c, rear_c);
			break;
		case 'c'://出队
			if (flag == -1)
			{
				printf("未创建数组,请先创建队列\n");
				system("pause");
				break;
			}
			if (flag == 0)queue_array_dequeue(&head_a);
			if (flag == 1)queue_chained_dequeue(head_c);
			break;
		case 'n'://结束
			goto end;
			break;
		default:
			break;
		};
	}
end:
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 10

/*����ͼ����*/
struct undigraph
{
    int vex_num; //����
    char *vex;
    int *arc; //�߹�ϵ
};

/*����ͼ����*/
struct node
{
    union {
        char value;
        int index;
    };
    node *next; //��ϵ����
};

struct digraph
{
    int num;
    node *vex_list;
};

void flash()
{
    scanf("%*[^\n]"); //��ջ����������һ��\nǰ���������ݣ��ٶ�ȡ�����һ��\n
    scanf("%*c");
}

undigraph *undigraph_create()
{
    int vex_num = 0, flag = 0, i = 0, j = 0, temp = 0;
    ;
    undigraph *new_graph = NULL;
    new_graph = (undigraph *)malloc(sizeof(undigraph));
    if (!new_graph)
    {
        perror("����ͼ�ڴ����ʧ��\n");
        return NULL;
    }
    do
    {
        flash();
        printf("�����붥���������������ڵ���0������������0������ͼ\n");
        flag = scanf("%d", &vex_num);
    } while (!flag || vex_num < 0);
    new_graph->vex_num = vex_num;
    if (!vex_num)
    {
        new_graph->arc = NULL;
        new_graph->vex = NULL;
        return new_graph;
    }
    new_graph->arc = (int *)malloc(sizeof(int) * vex_num * vex_num);
    new_graph->vex = (char *)malloc(sizeof(char) * vex_num);
    if (!new_graph->arc || !new_graph->vex)
    {
        perror("���󴴽�ʧ��\n");
        free(new_graph);
        return NULL;
    }
    printf("�����붥�㼯\n");
    for (i = 0; i < vex_num; i++)
    {
        getchar();
        scanf("%s", &new_graph->vex[i]);
    }
    printf("������ͼ���ٽӾ��󣬵�ǰ���������Ϊ%d�׾���\n", vex_num);
    for (i = 0; i < vex_num; i++)
    {
        for (j = 0; j < vex_num; j++)
        {
            scanf("%d", &temp);
            if (temp > 1)
                temp = 1;
            if (temp < 0)
                temp = 0;
            new_graph->arc[i * vex_num + j] = temp;
        }
    }
    printf("��ǰ������ٽӾ���Ϊ:\n");
    for (i = 0; i < vex_num; i++)
    {
        for (j = 0; j < vex_num; j++)
        {
            printf("%d ", new_graph->arc[i * vex_num + j]);
        }
        printf("\n");
    }
    system("pause");
    return new_graph;
}

int undig_depth_traversal(undigraph *G, int *array_, int node)
{
    int i = 0;
    if (!G || !array_)
    {
        perror("�������ݴ���\n");
        return -1;
    }
    if (array_[node])
        return 0;
    else
    {
        printf("%c ", G->vex[node]);
        array_[node] = 1;
    }
    for (i = 0; i < G->vex_num; i++) //���ݾ�������
    {
        if (!array_[i] && G->arc[node * G->vex_num + i])
        {
            undig_depth_traversal(G, array_, i);
        }
    }
    return 0;
}

int undig_spread_traversal(undigraph *G, int *array_ , int node_in)
{
    if (node_in >= G->vex_num || node_in < 0)
        return 0;
    int *queue = (int *)malloc(sizeof(int) * G->vex_num);
    if (!queue)
    {
        perror("�ڴ�������");
        return -1;
    }
    int head = 0, rear = 0, i = 0, node = 0;
    queue[rear++] = node_in;
    array_[node_in] = 1;
    while (1)
    {
        if (head == rear)
            break;
        node = queue[head++];
        printf("%c ", G->vex[node]);
        array_[node] = 1;
        for (i = 0; i < G->vex_num; i++)
        {
            if (!array_[i] && G->arc[node * G->vex_num + i])
            {
                queue[rear++] = i;
            }
        }
        for (i = 0; i < G->vex_num; i++)
        {
            if (!array_[i])
                break;
        }
        if (i >= G->vex_num)
            break;
    }
    for ( i = 0; i < G->vex_num; i++)
    {
        if (!array_[i])
            undig_spread_traversal(G, array_, i);
    }
    return 0;
}

digraph *digraph_create()
{
    digraph *new_graph = (digraph *)malloc(sizeof(digraph));
    node *temp = NULL, *temp_rear = NULL;
    int flag = 0, vex_num = 0, i = 0, j = 0;
    char temp_value[MAX_NUM] = {0};
    if (!new_graph)
        return NULL;
    do
    {
        flash();
        printf("�����붥���������������ڵ���0������������0������ͼ\n");
        flag = scanf("%d", &vex_num);
    } while (!flag || vex_num < 0);
    new_graph->num = vex_num;
    if (!vex_num)
    {
        new_graph->vex_list = NULL;
        return new_graph;
    }
    else
        new_graph->vex_list = (node *)malloc(sizeof(node) * vex_num);
    if (!new_graph->vex_list)
    {
        free(new_graph);
        return NULL;
    }
    else
    {
        printf("�����붥��\n");
        for (i = 0; i < vex_num; i++) //���붥�㼯
        {
            flash();
            scanf("%s", &new_graph->vex_list[i].value);
            new_graph->vex_list[i].next = NULL;
        }
        for (i = 0; i < vex_num; i++)
        {
            printf("�����붥��%s���ٽӶ���\n", &new_graph->vex_list[i].value);
            temp_rear = NULL;
            while (1)
            {
                printf("����0��������,���������\n");
                flash();
                scanf("%d", &flag);
                if (!flag)
                {
                    break;
                }
                else
                {
                    while (1) //�޶�Ӧ������������
                    {
                        printf("���������ڶ���\n");
                        flash();
                        scanf("%s", temp_value);
                        for (j = 0; j < vex_num; j++)
                        {
                            if (strcmp(temp_value, &new_graph->vex_list[j].value) == 0)
                                goto next;
                        }
                        printf("ͼ���޶�Ӧ���㣬����������\n");
                    }
                next:
                    temp = (node *)malloc(sizeof(node));
                    if (!temp)
                    {
                        free(new_graph);
                        return NULL;
                    }
                    temp->index = j;
                    if (!new_graph->vex_list[i].next)
                    {
                        new_graph->vex_list[i].next = temp;
                        temp->next = NULL;
                        temp_rear = temp;
                    }
                    else
                    {
                        temp_rear->next = temp;
                        temp->next = NULL;
                        temp_rear = temp;
                    }
                }
            }
        }
    }
    return new_graph;
}

int digraph_depth_traversal(digraph *G, int *array_, int node)
{
    if (!array_ || !G)
        return 0;
    if (array_[node])
        return 0;
    else
    {
        struct node *temp = G->vex_list[node].next;
        printf("%c ", G->vex_list[node].value);
        array_[node] = 1;
        while (temp)
        {
            if (!array_[temp->index])
                digraph_depth_traversal(G, array_, temp->index);
            temp = temp->next;
        }
    }
    return 0;
}

int digraph_spread_traversal(digraph *G, int *array_,int node_in)
{
    if (node_in >= G->num || node_in < 0)
        return 0;
    int *queue = (int *)malloc(sizeof(int) * G->num * 2);
    if (!queue)
    {
        perror("�ڴ�������");
        return -1;
    }
    int head = 0, rear = 0, i = 0, node = 0;
    struct node *temp = NULL;
    queue[rear++] = node_in;
    array_[node_in] = 1;
start:
    while (1)
    {
        if (head == rear)
            break;
        node = queue[head++];
        printf("%s ", &G->vex_list[node].value);
        array_[node] = 1;
        temp = G->vex_list[node].next;
        while (temp)
        {
            if(!array_[temp->index])queue[rear++] = temp->index;
            temp = temp->next;
        }
    }
    for (i = 0; i < G->num; i++)
    {
        if (!array_[i])
        {
            queue[rear++] = i;
            goto start;
        }
            
    }
    return 0;
}

int main()
{
    /*
    undigraph *graph = NULL;
    graph = undigraph_create();
    int *array_ = NULL;
    int i = 0;
    array_ = (int *)malloc(sizeof(int) * graph->vex_num);
    if (array_)
    {
        for (i = 0; i < graph->vex_num; i++)
            array_[i] = 0;
    }
    undig_spread_traversal(graph, array_);
    */
    digraph *graph = NULL;
    int *array_ = NULL;
    int i = 0;
    graph = digraph_create();
    array_ = (int *)malloc(sizeof(int) * graph->num);
    if (array_)
    {
        for (i = 0; i < graph->num; i++)
            array_[i] = 0;
    }
    digraph_spread_traversal(graph, array_, 0);
    return 0;
}
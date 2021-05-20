//����һ������ͼ���ڽ������ʾ��ʵ�ֶ�ͼ��������Ⱥ͹�����ȱ�����
#include <stdio.h>
#include <stdlib.h> //ͷ�ļ�
#define Max 10      //�趨����ඥ����
int visited[Max];   //����ķ��ʱ������
int visited1[Max];
typedef char ElemType;
typedef struct node
{
    int num;           //�߻򻡵�������
    struct node *next; //�߻򻡵�ָ����
} slink;               //�߻򻡵Ľ������
typedef struct
{
    struct
    {
        ElemType vertex; //�����������
        slink *first;    //�����ָ����
    } ve[Max];           //�������Ϣ�ṹ
    int vex;             //������
    int edge;            //����
} adjlist;

int cregraph(adjlist *G, int n) //��������ͼ�ڽӱ�
{
    int i, e = 0;
    slink *p, *q, *s;
    char x, y;
    G->vex = n;
    for (i = 0; i < n; i++)
    {
        G->ve[i].vertex = 'A' + i;
        G->ve[i].first = NULL; //��ʼ���ڽӱ�
    }
    printf("������ߣ�x--->y����"); //�ô�д��ĸ��ʾ����
    getchar();
    scanf("%c%c", &x,&y);
    while (x != ' ' && y != ' ') //����ߣ����ո������
    {
        e++;                                //ͳ�Ʊߵ���Ŀ
        s = (slink *)malloc(sizeof(slink)); //���ɽ�㣬������Ӧ�����Ұ����ֵ����
        s->num = y - 'A';
        if (G->ve[x - 'A'].first == NULL) //���뵽������
        {
            G->ve[x - 'A'].first = s;
            s->next = NULL;
        }
        else
        {
            p = G->ve[x - 'A'].first;
            if (p->num > s->num) //���뵽��һ�����ǰ
            {
                s->next = p;
                G->ve[x - 'A'].first = s;
            }
            else //����λ�ã��ٲ���
            {
                q = p->next;
                while (q != NULL && s->num > q->num)
                {
                    p = q;
                    q = q->next;
                }
                p->next = s;
                s->next = q;
            }
        }
    }
    G->edge = e;
    return 1;
}

int output(adjlist *G) //����ڽӱ�
{
    int i;
    slink *p;
    for (i = 0; i < G->vex; i++)
    {
        printf("%d:%c--->", i, G->ve[i].vertex); //���������Ϣ
        p = G->ve[i].first;
        while (p)
        {
            printf("%3d", p->num); //�����ö����й����Ķ���
            p = p->next;
        }
        printf("\n");
    }
    return 1;
}

void dfs(adjlist *G, int v) //��ȱ���
{
    slink *p;
    printf("%3c", G->ve[v].vertex);
    visited[v] = 1; //�÷��ʱ��
    p = G->ve[v].first;
    while (p)
    {
        if (!visited[p->num]) //��v��δ���ʹ����ڽӵ����
            dfs(G, p->num);   //�ٽ�����������������ݹ飩
        p = p->next;          //��v����һ���ڽӵ�
    }
}

void DFS(adjlist *G) //���в���ͨ�Ĳ��֣���������ȥ����
{
    int i;
    for (i = 0; i < G->vex; i++)
    {
        if (!visited[i])
            dfs(G, i);
    }
}

void bfs(adjlist *G, int v)
{
    int queue[Max], front, rear, i; //����һ���������
    slink *p;
    front = rear = 0;     //���г�ʼ��Ϊ��
    queue[rear++] = v;    //��ʼ���������
    while (front != rear) //���в���
    {
        v = queue[front++];              //������
        printf("%c->", G->ve[v].vertex); //����
        visited1[v] = 1;                 //�÷��ʱ��
        p = G->ve[v].first;
        while (p != NULL)
        {
            for (i = 0; i < rear; i++)
                if (p->num == queue[i])
                    break;
            if (i >= rear)
                queue[rear++] = p->num; //�����ڽӵ�û�����ʹ��Ҳ��ڶ����У��������
            p = p->next;                //��v����һ���ڽӵ�
        }
    }
}

void BFS(adjlist *G) //���в���ͨ�Ĳ��֣���������ȥ����
{
    int i;
    for (i = 0; i < G->vex; i++)
        if (!visited1[i])
            bfs(G, i);
}

int main()
{
    int v;
    int n = 0;
    adjlist a;
    adjlist *G = &a;
    printf("������ӱ�\n");
    printf("�����붥����\n");
    scanf("%d", &n);
    cregraph(G, n);
    printf("�����ӱ�Ϊ��\n");
    output(G);
    printf("�������������㣺");
    scanf("%d", &v);
    printf("��ȱ������Ϊ��\n");
    DFS(G);
    printf("��ȱ������Ϊ��\n");
    BFS(G);
    return 1;
}
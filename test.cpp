//建立一个有向图的邻接链表表示，实现对图的深度优先和广度优先遍历。
#include <stdio.h>
#include <stdlib.h> //头文件
#define Max 10      //设定的最多顶点数
int visited[Max];   //顶点的访问标记数组
int visited1[Max];
typedef char ElemType;
typedef struct node
{
    int num;           //边或弧的数据域
    struct node *next; //边或弧的指针域
} slink;               //边或弧的结点类型
typedef struct
{
    struct
    {
        ElemType vertex; //顶点的数据域
        slink *first;    //顶点的指针域
    } ve[Max];           //顶点的信息结构
    int vex;             //顶点数
    int edge;            //边数
} adjlist;

int cregraph(adjlist *G, int n) //创建有向图邻接表
{
    int i, e = 0;
    slink *p, *q, *s;
    char x, y;
    G->vex = n;
    for (i = 0; i < n; i++)
    {
        G->ve[i].vertex = 'A' + i;
        G->ve[i].first = NULL; //初始化邻接表
    }
    printf("请输入边（x--->y）："); //用大写字母表示顶点
    getchar();
    scanf("%c%c", &x,&y);
    while (x != ' ' && y != ' ') //输入边，遇空格符结束
    {
        e++;                                //统计边的数目
        s = (slink *)malloc(sizeof(slink)); //生成结点，插入相应链表且按结点值升序
        s->num = y - 'A';
        if (G->ve[x - 'A'].first == NULL) //插入到空链表
        {
            G->ve[x - 'A'].first = s;
            s->next = NULL;
        }
        else
        {
            p = G->ve[x - 'A'].first;
            if (p->num > s->num) //插入到第一个结点前
            {
                s->next = p;
                G->ve[x - 'A'].first = s;
            }
            else //先找位置，再插入
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

int output(adjlist *G) //输出邻接表
{
    int i;
    slink *p;
    for (i = 0; i < G->vex; i++)
    {
        printf("%d:%c--->", i, G->ve[i].vertex); //输出顶点信息
        p = G->ve[i].first;
        while (p)
        {
            printf("%3d", p->num); //输出与该顶点有关联的顶点
            p = p->next;
        }
        printf("\n");
    }
    return 1;
}

void dfs(adjlist *G, int v) //深度遍历
{
    slink *p;
    printf("%3c", G->ve[v].vertex);
    visited[v] = 1; //置访问标记
    p = G->ve[v].first;
    while (p)
    {
        if (!visited[p->num]) //从v的未访问过的邻接点出发
            dfs(G, p->num);   //再进行深度优先搜索（递归）
        p = p->next;          //找v的下一个邻接点
    }
}

void DFS(adjlist *G) //若有不连通的部分，则再跳过去遍历
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
    int queue[Max], front, rear, i; //定义一个分离队列
    slink *p;
    front = rear = 0;     //队列初始化为空
    queue[rear++] = v;    //初始顶点入队列
    while (front != rear) //队列不空
    {
        v = queue[front++];              //出队列
        printf("%c->", G->ve[v].vertex); //访问
        visited1[v] = 1;                 //置访问标记
        p = G->ve[v].first;
        while (p != NULL)
        {
            for (i = 0; i < rear; i++)
                if (p->num == queue[i])
                    break;
            if (i >= rear)
                queue[rear++] = p->num; //若该邻接点没被访问过且不在队列中，则入队列
            p = p->next;                //找v的下一个邻接点
        }
    }
}

void BFS(adjlist *G) //若有不连通的部分，则再跳过去访问
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
    printf("创建领接表\n");
    printf("请输入顶点数\n");
    scanf("%d", &n);
    cregraph(G, n);
    printf("输出领接表为：\n");
    output(G);
    printf("请输入遍历的起点：");
    scanf("%d", &v);
    printf("深度遍历结果为：\n");
    DFS(G);
    printf("广度遍历结果为：\n");
    BFS(G);
    return 1;
}
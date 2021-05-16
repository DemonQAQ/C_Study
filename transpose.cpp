#include <stdio.h>
#include <stdlib.h>

#define TYPE int

struct node
{
    int row; //行
    int col; //列
    TYPE data;
};

struct list
{
    int row;
    int col;
    int num;
    node *array;
};

TYPE scanf_reset(TYPE *value, long double min_edge, long double max_edge)
{
    if (min_edge >= max_edge)
        return 0;
    int flag = -1;
    long double value_temp = 0;
    do
    {
        flag = scanf("%lf", &value_temp);
    } while (flag == 0 || value_temp < min_edge || value_temp > max_edge);
    *value = (TYPE)value_temp;
    return 1;
}

TYPE *two_deminson_array_create(int *row, int *col) //创建二维数组
{
    int i = 0, j = 0, select = 0;
    TYPE *array_two = NULL;

    printf("请输入二维数组的行数，范围为(1 - 128)\n回车并且输入数据正确则结束输入\n");
    scanf_reset(row, 1, 128);
    printf("请输入二维数组的列数数，范围为(1 - 128)\n回车并且输入数据正确则结束输入\n");
    scanf_reset(col, 1, 128);

    array_two = (TYPE *)malloc(sizeof(TYPE) * (*row) * (*col));
    if (!array_two)
        exit(-1);
    for (i = 0; i < (*row) * (*col); i++) //初始化为0
        array_two[i] = 0;
    return array_two;
}

TYPE *two_deminson_array_input(TYPE *array, int row, int col) //稀疏矩阵非零元素的输入
{
    int i = 0, j = 0, select = 0;
    while (1)
    {
        system("cls");
        while (getchar() != '\n')
            ;
        printf("请输入稀疏矩阵的非零元素的行号和列号\n");
        printf("请输入行号，范围为[0 - %d),回车并且输入数据正常则结束输入\n", row - 1);
        scanf_reset(&i, 0, (unsigned int)row - 1);
        printf("请输入列号，范围为[0 - %d),回车并且输入数据正常则结束输入\n", col - 1);
        scanf_reset(&j, 0, (unsigned int)col - 1);
        printf("请输入元素的值,范围为(-25565 - 25565)\n");
        scanf_reset(&array[(i * (col)) + j], -25565, 25565);
        printf("输入数字-1结束输入，任意数字继续输入\n");
        while (getchar() != '\n')
            ;
        scanf("%d", &select);
        if (select == -1)
            break;
    }
    return array;
}

list *form_create(TYPE *array, int row, int col) //三元组表创建
{
    int i = 0, j = 0;
    list *form = NULL;
    node *array_temp = NULL;
    form = (list *)malloc(sizeof(list));
    if (form == NULL)
        exit(-1);
    //初始化
    form->num = 0;
    form->row = row;
    form->col = col;
    form->array = NULL;
    array_temp = (node *)malloc(sizeof(node) * row * col);
    if (!array_temp)
    {
        return form;
    }
    //搜索稀疏矩阵中的非零元素输入三元组表内
    //按行列循环
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (array[i * row + j] != 0)
            {
                array_temp[form->num].row = i;
                array_temp[form->num].col = j;
                array_temp[form->num++].data = array[i * row + j];
            }
        }
    }
    form->array = array_temp;
    return form;
}

void form_display(list *form) //输出三元组表的内容
{
    for (int i = 0; i < form->num; i++)
    {
        printf("i:%d j:%d data:%d\t\n", (*form).array[i].row, (*form).array[i].col, (*form).array[i].data);
    }
    printf("\n");
}

void sort(list *form)
{
    node temp;
    int i = 0, j = 0;
    for (i = 0; i < form->num - 1; i++)
    {
        for (j = i+1; j < form->num; j++)
        {
            if (form->array[i].row > form->array[j].row)
            {
                temp.row = form->array[i].row;
                temp.col = form->array[i].col;
                temp.data = form->array[i].data;

                form->array[i].row = form->array[j].row;
                form->array[i].col = form->array[j].col;
                form->array[i].data = form->array[j].data;

                form->array[j].row = temp.row;
                form->array[j].col = temp.col;
                form->array[j].data = temp.data;
            }
            if (form->array[i].row==form->array[j].row)
            {
                if (form->array[i].col > form->array[j].col)
                {
                    temp.row = form->array[i].row;
                    temp.col = form->array[i].col;
                    temp.data = form->array[i].data;

                    form->array[i].row = form->array[j].row;
                    form->array[i].col = form->array[j].col;
                    form->array[i].data = form->array[j].data;

                    form->array[j].row = temp.row;
                    form->array[j].col = temp.col;
                    form->array[j].data = temp.data;
                }
            }
        }
    }
}

list *transpose(list *form) //转置
{
    int temp = 3, i = 0;
    for (i = 0; i < form->num; i++)
    {
        temp = form->array[i].col;
        form->array[i].col = form->array[i].row;
        form->array[i].row = temp;
    }
    return form;
}

int main()
{
    TYPE *array = NULL;
    int row = 0, col = 0;
    list *form = NULL;
    array = two_deminson_array_create(&row, &col);
    array = two_deminson_array_input(array, row, col);
    printf("\n\n当前输入的矩阵为：\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", array[(i * row) + j]);
        }
        printf("\n");
    }
    printf("转置前的三元组表内数据为：\n");
    form = form_create(array, row, col);
    form_display(form);
    printf("转置后的三元组表内数据为：\n");
    form = transpose(form);
    sort(form);
    form_display(form);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define TYPE int

struct node
{
    int row; //��
    int col; //��
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

TYPE *two_deminson_array_create(int *row, int *col) //������ά����
{
    int i = 0, j = 0, select = 0;
    TYPE *array_two = NULL;

    printf("�������ά�������������ΧΪ(1 - 128)\n�س���������������ȷ���������\n");
    scanf_reset(row, 1, 128);
    printf("�������ά���������������ΧΪ(1 - 128)\n�س���������������ȷ���������\n");
    scanf_reset(col, 1, 128);

    array_two = (TYPE *)malloc(sizeof(TYPE) * (*row) * (*col));
    if (!array_two)
        exit(-1);
    for (i = 0; i < (*row) * (*col); i++) //��ʼ��Ϊ0
        array_two[i] = 0;
    return array_two;
}

TYPE *two_deminson_array_input(TYPE *array, int row, int col) //ϡ��������Ԫ�ص�����
{
    int i = 0, j = 0, select = 0;
    while (1)
    {
        system("cls");
        while (getchar() != '\n')
            ;
        printf("������ϡ�����ķ���Ԫ�ص��кź��к�\n");
        printf("�������кţ���ΧΪ[0 - %d),�س��������������������������\n", row - 1);
        scanf_reset(&i, 0, (unsigned int)row - 1);
        printf("�������кţ���ΧΪ[0 - %d),�س��������������������������\n", col - 1);
        scanf_reset(&j, 0, (unsigned int)col - 1);
        printf("������Ԫ�ص�ֵ,��ΧΪ(-25565 - 25565)\n");
        scanf_reset(&array[(i * (col)) + j], -25565, 25565);
        printf("��������-1�������룬�������ּ�������\n");
        while (getchar() != '\n')
            ;
        scanf("%d", &select);
        if (select == -1)
            break;
    }
    return array;
}

list *form_create(TYPE *array, int row, int col) //��Ԫ�����
{
    int i = 0, j = 0;
    list *form = NULL;
    node *array_temp = NULL;
    form = (list *)malloc(sizeof(list));
    if (form == NULL)
        exit(-1);
    //��ʼ��
    form->num = 0;
    form->row = row;
    form->col = col;
    form->array = NULL;
    array_temp = (node *)malloc(sizeof(node) * row * col);
    if (!array_temp)
    {
        return form;
    }
    //����ϡ������еķ���Ԫ��������Ԫ�����
    //������ѭ��
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

void form_display(list *form) //�����Ԫ��������
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

list *transpose(list *form) //ת��
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
    printf("\n\n��ǰ����ľ���Ϊ��\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", array[(i * row) + j]);
        }
        printf("\n");
    }
    printf("ת��ǰ����Ԫ���������Ϊ��\n");
    form = form_create(array, row, col);
    form_display(form);
    printf("ת�ú����Ԫ���������Ϊ��\n");
    form = transpose(form);
    sort(form);
    form_display(form);
    return 0;
}
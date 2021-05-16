#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <function.h>

#define TYPE intw

binary_tree *Create() //前序遍历顺序输入数据创建二叉树
{
    binary_tree *bt = NULL;
    TYPE value = 0;
    int flag = -1;
    flag = scanf("%d", &value);
    if (!flag)
        getchar();
    else
    {
        bt = (binary_tree *)malloc(sizeof(binary_tree));
        if (bt == NULL)
            exit(-1);
        bt->value = value;
        bt->lchild = Create();
        bt->rchild = Create();
    }
    return bt;
}

int Find_Height(binary_tree *root)
{
    binary_tree *temp_root = root;
    int Height = 0;
    int Height_left = 0;
    int Height_right = 0;
    if (root == NULL)
        return 0;
    else
    {
        Height_left = Find_Height(root->lchild);
        Height_right = Find_Height(root->rchild);
        Height = ((Height_left > Height_right) ? Height_left : Height_right) + 1;
        return Height;
    }
}

int node_num(binary_tree *root)
{
    int num = 0;
    binary_tree *temp_root = root;
    if (temp_root == NULL)
        return 0;
    if (temp_root->lchild || temp_root->rchild)
    {
        num++;
        if (temp_root->lchild)
            num += node_num(temp_root->lchild);
        if (temp_root->rchild)
            num += node_num(temp_root->rchild);
    }
    return num;
}

int node_num_singlechild(binary_tree *root)
{
    int num = 0;
    binary_tree *temp_root = root;
    if (temp_root == NULL)
        return 0;
    if (temp_root->lchild && !temp_root->rchild || temp_root->rchild && !temp_root->lchild)
    {
        num++;
    }
    if (temp_root->lchild)
        num += node_num_singlechild(temp_root->lchild);
    if (temp_root->rchild)
        num += node_num_singlechild(temp_root->rchild);
    return num;
}

int node_num_leaf(binary_tree *root)
{
    int num = 0;
    binary_tree *temp_root = root;
    if (!temp_root->lchild && !temp_root->rchild)
    {
        num++;
    }
    else
    {
        if (temp_root->lchild)
            num += node_num_leaf(temp_root->lchild);
        if (temp_root->rchild)
            num += node_num_leaf(temp_root->rchild);
    }
    return num;
}

binary_tree *preorder_traversal(binary_tree *root)
{
    binary_tree *temp_root = root;
    if (!temp_root)
        printf("#");
    else
    {
        printf("%d", temp_root->value);
        preorder_traversal(temp_root->lchild);
        preorder_traversal(temp_root->rchild);
    }
    return temp_root;
}

void Display()
{
    printf("\t\t\t\t二叉树\n");
    printf("\t\t\ta.创建二叉树\n");
    printf("\t\t\tb.计算二叉树高度\n");
    printf("\t\t\tc.计算二叉树节点数目\n");
    printf("\t\t\td.计算二叉树单孩子节点数目\n");
    printf("\t\t\te.计算二叉树叶子节点数目\n");
    printf("\t\t\tf.先序遍历输出二叉树\n");
    printf("\t\t\tn.退出\n");
}

int main()
{
    binary_tree *root = NULL;
    int n = 0;
    char select = 0;
    while (1)
    {
        system("cls");
        Display();
        fflush(stdin);
        scanf("%c", &select);
        fflush(stdin);
        switch (select)
        {
        case 'a':
            if (root)
            {
                printf("已有二叉树，输入Y/y重新创建二叉树");
                fflush(stdin);
                scanf("%c", &select);
                fflush(stdin);
                if (select == 'y' || select == 'Y')
                {
                    root = Create();
                    system("pause");
                    system("cls");
                }
                else
                    break;
            }
            else
            {
                root = Create();
                system("pause");
                system("cls");
                break;
            }
        case 'b':
            n = Find_Height(root);
            printf("当前二叉树高度为 %d", n);
            system("pause");
            system("cls");
            break;
        case 'c':
            n = node_num(root);
            printf("当前二叉树节点数目为 %d", n);
            system("pause");
            system("cls");
            break;
        case 'd':
            n = node_num_singlechild(root);
            printf("当前二叉树单孩子节点数目为 %d", n);
            system("pause");
            system("cls");
            break;
        case 'e':
            n = node_num_leaf(root);
            printf("当前二叉树叶子节点数目为 %d", n);
            system("pause");
            system("cls");
            break;
        case 'f':
            preorder_traversal(root);
            system("pause");
            system("cls");
            break;
        case 'n':
            goto end;
        default:
            break;
        }
    }
end:
    return 0;
}
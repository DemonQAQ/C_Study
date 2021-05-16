#include <stdio.h>
#include <stdlib.h>
#include <function.h>
int main()
{
    /*
    int x = 60;
    x >>= 1;
    printf("%d",x);
    */
    binary_tree bt,bt1;
    binary_tree *temp = NULL;
    bt.value = 0;
    queue *test=NULL;
    test = create(test);
    test = inqueue(test, &bt1);
    test = inqueue(test, &bt);
    temp = dequeue(test);
    printf("%d %d", temp, &bt);
    return 0;
}
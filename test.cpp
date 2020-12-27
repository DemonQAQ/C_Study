#include <stdio.h>
int main()
{
    char c;
    int eng = 0, num = 0, space = 0, other = 0;
    //c = getchar();
    while ((c = getchar()) != '\n')
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            eng++;
        else if (c >= '0' && c<= '9')
            num++;
        else if (c == ' ')
            space++;
        else
            other++;

    }
    printf("%d,%d,%d,%d", eng, num, space, other);
    return 0;
}
#include <stdio.h>
int main()
{
    int *p, x=0;
    p = &x;
    printf("inicial:\n p = %d e *p = %d\n", p,*p);
    p++;
    printf("p++:\n p = %d e *p = %d\n", p,*p);
    (*p)++;
    printf("(*p)++:\n p = %d e *p = %d\n", p,*p);
    *(++p);
    printf("*(++p):\n p = %d e *p = %d\n", p,*p);
    *(p+10);
    printf("*(p+10):\n p = %d e *p = %d\n", p,*p);
}
#include <stdio.h>

int main()
{
    int x, *p1, **p2, ***p3;
    
    p1 = &x;
    p2 = &p1;
    p3 = &p2;

    printf("Enter the number\n");
    scanf("%d", &x);
    printf("The value of x is %d\n", x);
    printf("Enter the number\n");
    scanf("%d", p1);
    printf("The value of x is %d\n", *p1);
    printf("Enter the number\n");
    scanf("%d", *p2);
    printf("The value of x is %d\n", **p2);
    printf("Enter the number\n");
    scanf("%d", **p3);
    printf("The value of x is %d\n", ***p3);
    return 0;
}
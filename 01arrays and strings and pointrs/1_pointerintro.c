#include<stdio.h>

int main(){
    int x,y;
    int *p1,*p2;

    p1=NULL;
    p2=NULL;
    printf("The value of p1 and p2 when initialized to null is %u %u\n",p1,p2);
    p1=&x;
    p2=&y;

    printf("Enter x and y\n");
    scanf("%d %d",p1,p2);

    printf("The address of x and y is %u , %u\n",p1,p2);

    printf("The value of x and y is %d and %d\n",*p1,*p2);
    return 0;
}
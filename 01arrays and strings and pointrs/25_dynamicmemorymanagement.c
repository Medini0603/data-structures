#include<stdio.h>

int main(){
    //void pointer
    void *ptr;
    int x=10;
    char c='m';
    float f=121.0;
    ptr=&x;
    printf("The value of integer x is %d\n",*(int*)ptr);//casting is required from void * to int *
    ptr=&c;
    printf("The value of character is %c\n",*(char *)ptr);
    ptr=&f;
    printf("The value of floating point is %f\n",*(float *)ptr);
    return 0;
}
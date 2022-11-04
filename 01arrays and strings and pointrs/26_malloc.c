#include<stdio.h>
#include<stdlib.h>
void read(int *);
void disp(int *);
int main(){
    int *p;
    p=(int *)malloc(5*sizeof(int));
    read(p);
    disp(p);
    return 0;
}
void read(int *p){
    printf("\nEnter the elements one by one\n");
    for(int i=0;i<5;i++)
        scanf("%d",p+i);
}

void disp(int *p){
    printf("\nThe elemnts you entered are\n");
    for(int i=0;i<5;i++)
        printf("%d\t",*(p+i));
}
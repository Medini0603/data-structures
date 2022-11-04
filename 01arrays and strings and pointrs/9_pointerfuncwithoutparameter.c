#include<stdio.h>
void swap(int*,int*);

int main(){
    int x,y,*px,*py;

    printf("Enter x and y\n");
    scanf("%d%d",&x,&y);

    printf("The values of x and y before swapping is %d %d\n",x,y);
    
    swap(&x,&y);

    printf("The swapped values of x and y after swapping is %d %d\n",x,y);
    return 0;
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
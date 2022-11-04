#include<stdio.h>

int main(){
    int x=10,y=20,*px,*py;
    px=&x;
    py=&y;

    printf("The initial values of x and y are %d and %d\n",*px,*py);

    *py = *px+3;
    printf("Updated value of y is %d\n",*py);

    *px=*py/2;
    printf("Updated value of x is %d\n",*px);

    if(*px>*py){*px++;}
    else{*py++;}
    printf("The updated values of x and y are %d %d\n",*px,*py);

     if(x>y){x++;}
    else{y++;}
    printf("The updated values of x and y are %d %d",x,y);
    
    return 0;
}
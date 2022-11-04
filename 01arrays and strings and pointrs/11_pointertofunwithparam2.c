#include<stdio.h>

int* max(int*,int*);

int main(){
    int a,b,*large;
    printf("Enter the numbers\n");
    scanf("%d%d",&a,&b);

    large=max(&a,&b);
    printf("The maximum among %d and %d is %d\n",a,b,*large);
    return 0;
}

int *max(int *a,int *b){
    if(*a>*b){return a;}
    else{return b;}
}
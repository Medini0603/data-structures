#include<stdio.h>
int max(int*,int*);

int main(){
    int x,y,large;
    printf("Enter the numbers\n");
    scanf("%d%d",&x,&y);

    large=max(&x,&y);
    printf("The largest among %d and %d is %d\n",x,y,large);
    return 0;
}

int max(int *a,int *b){
    if(*a>*b){return *a;}
    else return *b;
}
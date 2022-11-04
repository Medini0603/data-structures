#include<stdio.h>
int count = 0;
int fact(int n)
{
    count++;
    if(n==0)return 1;
    else return n*fact(n-1);
}
int main(){
    printf("Enter value of n\n");
    int n;
    scanf("%d",&n);
    int f=fact(n);
    printf("factorial = %d\n",f);
    printf("Number of calls %d",count);
    return 0;
}
#include<stdio.h>

int count=0;

int fib(int n)
{
    count++;
    if(n==1)return 0;
    if(n==2)return 1;
  //  printf("%d\t",fib(n-2));
     return fib(n-1)+fib(n-2);
}
int main(){
     printf("Enter value of n\n");
    int n;
    scanf("%d",&n);
    int f=fib(n);
    printf("\nfib = %d\n",f);
    printf("Number of calls %d",count);
    return 0;
}
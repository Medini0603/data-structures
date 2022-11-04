#include<stdio.h>
int count=0;
void printhello(int n)
{
    count++;
    if(n>0)
    {
        printf("%d hello world\n",n);
        return printhello(n-1);
    }
}
int main(){
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    printhello(n);
    return 0;
}
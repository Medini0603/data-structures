//Find the binary equivalent of a decimal integer. 

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int items[20];
    int top;
};
typedef struct stack STK;
void push(STK *,int);
void dectobin(int);

int main(){
    int n;
    printf("Enter number\n");
    scanf("%d",&n);
    printf("The binary number of entered digit is\n");
    dectobin(n);
    return 0;
}

void push(STK *s,int dig)
{
    s->top++;
    s->items[s->top]=dig;
}

void dectobin(int num)
{
    STK s;
    s.top=-1;
    int dig=0;
    while(num!=1)
    {
        dig=num%2;
        push(&s,dig);
        num=num/2;
    }
    s.top++;
    s.items[s.top]=1;

    char bin[20];
    while(s.top!=-1)
    {
        printf("%d",s.items[s.top]);
        s.top--;
    }
    printf("\n");
}
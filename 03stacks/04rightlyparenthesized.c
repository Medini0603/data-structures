//Check whether the infix expression is properly parenthesized or not.

#include<stdio.h>
#include<stdlib.h>
struct stack
{
    char items[20];
    int top;
};
typedef struct stack STK;
void push(STK*,char c);
int isparen(char[]);

void push(STK *,char);
int main(){
    char c[20];
    printf("Enter the expression\n");
    scanf("%s",c);
    int flag = isparen(c);
    if(flag)printf("It's correctly parenthesized\n");
    else printf("It's not correctly parenthesized\n");
    return 0;
}

void push(STK *s,char c)
{
    s->top++;
    s->items[s->top]=c;
}

int isparen(char c[])
{
    char t;
    int i=0; 
    int flag=0;
    STK s;
    s.top=-1;
    while((t=c[i++])!='\0')
    {
        if(t=='(')
        {
            push(&s,t);
            flag=1;
        }
        if(t==')')
            s.top--;
    }

    if(s.top==-1)
    return 1;
    else return 0;
}
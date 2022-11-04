#include <stdio.h>
#include <math.h>
#include<string.h>
typedef struct stack
{
    float items[20];
    int top;
} stk;

void push(stk *s, float n)
{
    s->top++;
    s->items[s->top] = n;
}

int isop(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '^':
    case '$':
        return 0;
    default:
        return 1;
    }
}

float pop(stk *s)
{
    float n = s->items[s->top];
    s->top--;
    return n;
}

void compute(stk *s, char c)
{
    float op1 = pop(s);
    float op2 = pop(s);
    float res;
    switch (c)
    {
    case '+':
        res = op1 + op2;
        break;

    case '-':
        res = op1 - op2;
        break;

    case '*':
        res = op1 * op2;
        break;

    case '/':
        res = op1 / op2;
        break;

    case '^':
        res = pow(op1, op2);
        break;

    case '$':
        res = pow(op1, op2);
        break;
    }

    push(s,res);
}

float evaluate(char pre[])
{
    strrev(pre);
    stk s;s.top=-1;
    int i=0,j=0;
    char c;
    while((c=pre[i++])!='\0')
    {
        if(isop(c))
        {
            push(&s,c-'0');
        }
        else
        {
            compute(&s,c);
        }
    }
    float result=pop(&s);
    return result;
}
int main()
{
 char pre[20];
    float result;
    printf("Enter your prefix expression\n");
    scanf("%s", pre);
    result=evaluate(pre);
    printf("The value of prefix expression is %f\n", result);
    return 0;
}
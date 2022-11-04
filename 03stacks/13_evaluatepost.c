#include <stdio.h>
#include <math.h>

typedef struct stack
{
    float items[20];
    int top;
} stk;

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

void push(stk *s, float n)
{
    s->top++;
    s->items[s->top] = n;
}

float pop(stk *s)
{
    float n = s->items[s->top];
    s->top--;
    return n;
}

void compute(stk *s,float op1, float op2, char c)
{
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

int evaluate(char post[])
{
    stk s;
    s.top = -1;
    int i = 0, j = 0;
    char c;
    float op1=0,op2=0;
    while ((c = post[i++]) != '\0')
    {
        if (isop(c))
        {
            int n = c - '0';
            push(&s, n);
        }

        else
        {
             op2 = pop(&s);
             op1 = pop(&s);
            compute(&s,op1, op2, c);
        }
    }
    float result = pop(&s);
    return result;
}
int main()
{
    char post[20];
    float result;
    printf("Enter your postfix expression\n");
    scanf("%s", post);
    result=evaluate(post);
    printf("The value of postfix expression is %f\n", result);
    return 0;
}
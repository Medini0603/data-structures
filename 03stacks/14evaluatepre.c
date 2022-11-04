#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct stack
{
    float items[20];
    int top;
} stk;

void push(stk *s, float c)
{
    s->top++;
    s->items[s->top] = c;
}

float pop(stk *s)
{
    float c = s->items[s->top];
    s->top--;
    return c;
}

int isop(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '$':
    case '^':
    case '(':
    case ')':
        return 0;
    default:
        return 1;
    }
}

float calculate(stk *s, char c)
{
    float op1 = pop(s);
    float op2 = pop(s);
    switch (c)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '$':
        return pow(op1, op2);
    case '^':
        return pow(op1, op2);
    }
}

float eval(char in[])
{
    int i = 0, j = 0;
    char c;
    stk s;
    s.top = -1;
    int n = strlen(in);
    n = n - 1;
    while (n >= 0)
    {
        c = in[n--];
        if (isop(c))
        {
            float n = c - '0';
            push(&s, n);
        }
        else
        {
            float res = calculate(&s, c);
            push(&s, res);
        }
    }
    float result = pop(&s);
    return result;
}
void main()
{
    char post[20];
    printf("Enter prefix expression\n");
    scanf("%s", post);
    float res = eval(post);
    printf("value of prefix expression : %f\n", res);
}

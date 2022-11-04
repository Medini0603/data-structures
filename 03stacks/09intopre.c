#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char items[20];
    int top;
} oprtrstk;

void push1(oprtrstk *s, char c)
{
    s->top++;
    s->items[s->top] = c;
}

char pop1(oprtrstk *s)
{
    char c = s->items[s->top];
    s->top--;
    return c;
}

typedef struct stack2
{
    char items[20][10];
    int top;
} oprndstk;

void push2(oprndstk *s, char c[])
{
    s->top++;
    strcpy(s->items[s->top], c);
}

char *pop2(oprndstk *s)
{
    char *c = s->items[s->top];
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

int stkprec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '$':
    case '^':
        return 6;
    case '(':
        return 0;
    }
}

int inprec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 7;
    case '(':
        return 10;
    case ')':
        return 0;
    }
}

void createpp(oprtrstk *s1, oprndstk *s2)

{
    char pp[20];
    char c = pop1(s1);
    char opr[2];
    opr[0] = c;
    opr[1] = '\0';
    char *op2 = pop2(s2);
    char *op1 = pop2(s2);
    strcpy(pp, opr);
    strcat(pp, op1);
    strcat(pp, op2);
    push2(s2, pp);
}

void intopre(char in[], char pre[])
{
    int i = 0, j = 0;
    char c;
    oprtrstk s1;
    s1.top = -1;
    oprndstk s2;
    s2.top = -1;
    char pp[2];

    while ((c = in[i++]) != '\0')
    {
        if (isop(c))
        {
            pp[0] = c;
            pp[1] = '\0';
            push2(&s2, pp);
        }
        else
        {
            while (s1.top != -1 && stkprec(s1.items[s1.top]) > inprec(c))
            {
                if (c == ')')
                {
                    while (s1.items[s1.top] != '(')
                        createpp(&s1, &s2);
                    s1.top--;
                    break;
                }
                else

                {
                    createpp(&s1, &s2);
                }
            }
            if (c != ')')
                push1(&s1, c);
        }
    }
    while (s1.top != -1)
        createpp(&s1, &s2);
    strcpy(pre, s2.items[s2.top]);
}

void main()
{
    char in[20], pre[20];
    printf("Enter infix expression\n");
    scanf("%s", in);
    intopre(in, pre);
    printf("prefix expression : %s\n", pre);
}
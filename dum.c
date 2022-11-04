#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char items[20];
    int top;
} stk;

void push(stk *s, char c)
{
    s->items[++s->top] = c;
}

char pop(stk *s)
{
    char c = s->items[s->top--];
    return c;
}

typedef struct stack2
{
    char items[20][20];
    int top;
} stk2;

void push2(stk2 *s, char c[])
{
    strcpy(s->items[++s->top], c);
}

char *pop2(stk2 *s)
{
    char *c = s->items[s->top--];
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
    case '^':
    case '$':
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
        return 3;
    case '*':
    case '/':
        return 5;
    case '^':
    case '$':
        return 7;
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
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 8;
    case '(':
        return 10;
    case ')':
        return 0;
    }
}

void createpp(stk *s, stk2 *s2)
{
    char temp[2];
    char *op1, *op2, opr;
    // opr = pop(s);
    op2 = pop2(s2);
    op1 = pop2(s2);
    temp[0] = pop(s);
    temp[1] = '\0';
    char pre[20];
    strcpy(pre, temp);
    strcat(pre, op1);
    strcat(pre, op2);

    push2(s2, pre);
}

void intopre(char in[], char pre[])
{
    int i = 0;
    char c;
    stk s;
    s.top = -1;
    stk2 s2;
    s2.top = -1;
    char temp[2];
    while ((c = in[i++]) != '\0')
    {
        if (isop(c))
        {
            temp[0] = c;
            temp[1] = '\0';
            push2(&s2, temp);
        }

        else
        {
            while (s.top != -1 && stkprec(s.items[s.top] > inprec(c)))
            {
                if (c == ')')
                {
                    while (s.items[s.top] != '(')
                        createpp(&s, &s2);
                    s.top--;
                    break;
                }

                else
                    createpp(&s, &s2);
            }

            if (c != ')')
                push(&s, c);
        }
    }

    while (s.top != -1)
        createpp(&s, &s2);

    strcpy(pre, s2.items[s2.top]);
}
int main()
{
    char in[20], pre[20];
    printf("Enter infix expression\n");
    scanf("%s", in);
    intopre(in, pre);
    printf("Coverted to prefix = %s\n", pre);
    return 0;
}
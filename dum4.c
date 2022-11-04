#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 20

typedef struct stk
{
    char item[size];
    int top;
} Stk;

void push(Stk *s, char c)
{
    if (s->top == size - 1)
        printf("stack is full \n");
    else
    {
        s->top++;
        s->item[s->top] = c;
    }
}

char pop(Stk *s)
{
    char c;
    if (s->top == -1)
    {
        printf("Stack is empty \n");
        return '\0';
    }
    else
    {
        c = s->item[s->top];
        s->top--; return c;
    }
}

int isoperand(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(':
        return 0;
    default:
        return 1;
    }
}

int stkpre(char c)
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
        return 7;
    case '(':
        return 0;
    }
}

int popre(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
        return 8;
    case '(':
        return 9;
    case ')':
        return 0;
    }
}

void inpo(char in[], char po[])
{
    Stk s;
    int i = 0, j = 0;
    char c;
    s.top = -1;
    while (c = in[i++] != '\0')
    {
        if (isoperand(c))
            po[j++] = c;

        else
        {
            while (s.top != -1 && stkpre(s.item[s.top]) > popre(c))
            {

                if (c == ')')
                {
                    while (s.item[s.top] != '(')
                        po[j++] = pop(&s);
                    pop(&s);
                    break;
                }

                else
                    po[j++] = pop(&s);
            }

            if (c != ')')
                push(&s, c);
        }
    }
    while (s.top != -1)
        po[j++] = pop(&s);
    po[j] = '\0';
}

void main()
{
    char in[size], po[size];
   
        printf("Enter the expression and 0 to stop the execution \n");
        scanf("%s", in);
        inpo(in, po);
        printf("%s", po);
    
}
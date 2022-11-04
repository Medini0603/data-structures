#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    char items[30];
    int top;
} STK;

void push(STK *s, char c)
{
    s->top++;
    s->items[s->top] = c;
}

char pop(STK *s)
{
    char c = s->items[s->top];
    s->top--;
    return c;
}

int isopernd(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '$':
    case '^':
    case ')':
    case '(':
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
        return 4;
    case '*':
    case '/':
        return 6;
    case '$':
    case '^':
        return 8;
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
        return 3;
      
    case '*':
    case '/':
        return 5;
      
    case '$':
    case '^':
        return 9;
     
    case '(':
        return 10;
    case ')':
        return 0;
      
    }
}

void intopost(char in[], char pos[])
{
    int i = 0, j = 0;
    STK s;
    s.top = -1;
    char c;
    while ((c = in[i++]) != '\0')
    {
        if (isopernd(c))
            pos[j++] = c;
        else
        {
            while (s.top != -1 && stkprec(s.items[s.top]) > inprec(c))
            {
                if (c == ')')
                {
                    while (s.items[s.top] != '(')
                        pos[j++] = pop(&s);
                   s.top--;
         /*impppp*/break;//if not included all elements in stack will be poped and next char of infix will not be scanned 
                }
                else
                    pos[j++] = pop(&s);//if break is not given then all stack operators are just poped:-(
            }
             if (c != ')')
                push(&s, c);
        }
    }

    while (s.top != -1)
        pos[j++] = pop(&s);
    pos[j] = '\0';
}

int main()
{
    char s[30];
    printf("Enter your infix expression\n");
    scanf("%s", s);
    char post[30];
    intopost(s, post);
    printf("The converted postfix expression is %s",post);
    return 0;
}
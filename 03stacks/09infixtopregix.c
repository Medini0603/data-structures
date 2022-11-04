//SAME AS POSTFIX BUT INSTEAD OF post[j++] WE DO createparexp(&s1,&op2)
//also we neeed two stacks
#include <stdio.h>
#include <string.h>
typedef struct stack
{
    char items[10][20];
    int top;
} OPRNDSTK;

void pushoprnd(OPRNDSTK *s, char c[])
{
    s->top++;
    strcpy(s->items[s->top], c);
}

char *popoprnd(OPRNDSTK *s)
{
    char *c;
    c = s->items[s->top];
    s->top--;
    return c;
}

typedef struct stack2
{
    char items[20];
    int top;
} OPRSTK;

void pushopt(OPRSTK *s, char c)
{
    s->top++;
    s->items[s->top] = c;
}

char popopt(OPRSTK *s)
{
    char c;
    c = s->items[s->top];
    s->top--;
    return c;
}

int isoprnd(char c)
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
    case '^':
    case '$':
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
    case '^':
    case '$':
        return 7;
    case '(':
        return 10;
    case ')':
        return 0;
    }
}
void createparexp(OPRNDSTK *s1, OPRSTK *s2)
{
    char opr[2];

    char temp = popopt(s2);
    opr[0] = temp;
    opr[1] = '\0';
    char *op1, *op2;
    op2 = popoprnd(s1);
    op1 = popoprnd(s1);
    char prefix[20];
    strcpy(prefix, opr);
    strcat(prefix, op1);
    strcat(prefix, op2);
    pushoprnd(s1, prefix);
}
void intopre(char in[], char pre[])
{
    OPRNDSTK soprnd;
    soprnd.top = -1;
    OPRSTK sopr;
    sopr.top = -1;
    int i = 0, j = 0;
    char c;
    char pp[2];
    while ((c = in[i++]) != '\0')
    {
        if (isoprnd(c))
        {
            pp[0] = c;
            pp[1] = '\0';
            pushoprnd(&soprnd, pp);
        }

        else
        {
            while (sopr.top != -1 && stkprec(sopr.items[sopr.top]) > inprec(c))
            {
                if (c == ')')
                {
                    while (sopr.items[sopr.top] != '(')
                        createparexp(&soprnd, &sopr);
                    sopr.top--;
                    break;
                }
                else
                    createparexp(&soprnd, &sopr);
            }
            if (c != ')')
                pushopt(&sopr, c);
        }
    }
    while (sopr.top != -1)
        createparexp(&soprnd, &sopr);
    strcpy(pre, soprnd.items[soprnd.top]);
}
int main()
{
    char s[30];
    printf("Enter your infix expression\n");
    scanf("%s", s);
    char post[30];
    intopre(s, post);
    printf("The converted prefix expression is %s", post);
    return 0;
}
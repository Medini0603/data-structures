#include <stdio.h>
#include <string.h>

typedef struct stack
{
    char items[10][20];
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

void push(stk *s, char c[])
{
    s->top++;
    strcpy(s->items[s->top], c);
}

char *pop(stk *s)
{
    char *c = s->items[s->top];
    s->top--;
    return c;
}

void ppost(stk *s, char oprt)
{
    char *op1;
    char *op2;
    char temp[2];
    temp[0] = oprt;
    temp[1] = '\0';
    char pexp[20];
    op1 = pop(s);
    op2 = pop(s);
    strcpy(pexp, op1);
    strcat(pexp, op2);
    strcat(pexp, temp);
    push(s, pexp);
}

void conpost(char pre[], char post[])
{
    stk s;
    s.top = -1;
    int i = 0, j = 0;
    char c;
    char temp[2];
  //  char *prefix=pre;
  char prefix[20];
  strcpy(prefix,pre);
    strrev(prefix);
    while ((c = prefix[i++]) != '\0')
    {
        if (isop(c))
        {
            temp[0] = c;
            temp[1] = '\0';
            push(&s, temp);
        }

        else
        {
            ppost(&s, c);
        }
    }

    strcpy(post, s.items[s.top]);
}

void ppin(stk *s,char c)
{
    char *op1,*op2,temp[2];
    temp[0]=c;
    temp[1]='\0';
    op1=pop(s);
    op2=pop(s);
    char infix[20];
    strcpy(infix,op1);
    strcat(infix,temp);
    strcat(infix,op2);
    push(s,infix);
}

void conin(char pre[], char in[])
{
    stk s;
    s.top = -1;
    int i = 0, j = 0;
    char c;
    char temp[2];
    char prefix[20];
    strcpy(prefix,pre);
    strrev(prefix);
    while ((c = prefix[i++]) != '\0')
    {
        if (isop(c))
        {
            temp[0] = c;
            temp[1] = '\0';
            push(&s, temp);
        }

        else
        {
            ppin(&s, c);
        }
    }
    strcpy(in, s.items[s.top]);
}

int main()
{
    char post[20];
    char in[20];
    char pre[20];
    printf("Enter your prefix expression\n");
    scanf("%s", pre);
    conin(pre, in);
    printf("The converted infix expression is %s\n", in);
    printf("The original prefix expression is %s\n", pre);
    conpost(pre, post);
    printf("The converted prefix expression is %s\n", post);
    return 0;
}
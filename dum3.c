#include<stdio.h>
typedef struct stack
{
    char items[20];
    int top;
}stk;

void push(stk *s,char c)
{
    s->top++;
    s->items[s->top]=c;
}

char pop(stk *s)
{
    char c=s->items[s->top];
    s->top--;
    return c;
}

int isop(char c)
{
switch(c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '$':
	case '(':
	case ')':return 0;
	default:return 1;
	}
}

int stkprec(char c)
{
switch(c)
	{
	case '+':
	case '-':return 3;
	case '*':
	case '/':return 5;
	case '^':
	case '$':return 7;
	case '(':return 0;
	}
}

int inprec(char c)
{
switch(c)
	{
	case '+':
	case '-':return 2;
	case '*':
	case '/':return 4;
	case '^':
	case '$':return 8;
	case '(':return 10;
	case ')':return 0;
	}
}

void intopost(char in[],char post[])
{
    int i=0,j=0;
    stk s;s.top=-1;
    char c;
    while((c=in[i++])!='\0')
    {
        if(isop(c))
            post[j++]=c;
        else
        {
            while(s.top!=-1 && stkprec(s.items[s.top])>inprec(c))
            {
                if(c==')')
                {
                    while(s.items[s.top]!='(')
                        post[j++]=pop(&s);
                    s.top--;
                    break;
                }

                else
                    post[j++]=pop(&s);
            }

            if(c!=')')
                push(&s,c);
        }
    }

    while(s.top!=-1)
        post[j++]=pop(&s);
    post[j]='\0';
}
int main(){
    char in[20],post[20];
    printf("Enter infix\n");
    scanf("%s",in);
    intopost(in,post);
    printf("Postfix = %s",post);
    return 0;
}
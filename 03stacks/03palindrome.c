// Check whether the given string is a palindrome or not .

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char items[20];
    int top;
};
typedef struct stack STK;

void push(STK *s, char c);
void ispalindrome(char s[]);

void main()
{
    char s[20];
    printf("Enter your string\n");
    scanf("%s", s);
    //  printf("%d",strlen(s));
    ispalindrome(s);
}

void push(STK *s, char c)
{
    s->top++;
    s->items[(s->top)] = c;
}

void ispalindrome(char c[])
{
    int i;
    STK s;
    s.top = -1;
    int n = strlen(c) / 2;
    if (strlen(c) % 2 != 0)
        n = ((strlen(c) - 1 )/ 2);
    for (i = 0; i < n; i++)
    {
        push(&s, c[i]);
    }

    int flag = 0;
    if (strlen(c) % 2 != 0)
        n=n+1;
    for (i = n; i < strlen(c); i++)
    {
        if (c[i] != s.items[s.top])
        {
            flag = 1;
            break;
        }
        s.top--;
    }

    if (flag == 1)
        printf("%s is not a palindrome\n", c);
    else
        printf("%s is a palindrome\n", c);
}
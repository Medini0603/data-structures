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
    STK s;
    s.top = -1;
    for (int i = 0; i < strlen(c); i++)
        push(&s, c[i]);
    int flag = 1;
    int i = 0;
    while (s.top != -1)
    {
        if (c[i] != s.items[s.top])
        {
            flag = 0;
            break;
        }

        i++;
        s.top--;
    }

    if (flag)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not palindrome\n");
    }
}
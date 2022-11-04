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
    s->top++;
    s->items[s->top] = c;
}

char pop(stk *s)
{
    char c = s->items[s->top];
    s->top--;
    return c;
}

int main()
{
    char m[20][10];
    printf("Enter number of words\n");
    int n;
    scanf("%d", &n);
    printf("Enter words one by one\n");
    for (int i = 0; i < n; i++)
        scanf("%s", m[i]);
    stk s;
    s.top = -1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = strlen(m[i]) - 1; j >= 0; j--)
        {
            if (m[i][j] == m[i + 1][j])
            {
                push(&s, m[i][j]);
            }

             if (m[i][j] != m[i + 1][j] && (s.top != m[i + 1][j]))
            {
                pop(&s);
                break;
            }
            if (m[i][j] != m[i + 1][j])
                break;
        }
    }
    char res[20];
    int i;
    for (i = 0; s.top != -1; i++)
    {
        res[i] = pop(&s);
    }
    res[i] = '\0';
    printf("The common sequence is %s\n", res);
    return 0;
}
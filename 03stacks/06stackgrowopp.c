// Create two stacks(Same type) in a single array.
// The two stacks should grow in opposite directions.
// The stacks are full only when the entire memory is utilized)
#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int *items;
    int top;
} stk;
void push1(stk *s1, stk *s2)
{
    if (s1->top == s2->top - 1)
    {
        printf("full\n");
        return;
    }

    s1->top++;
    printf("Enter item\n");
    int item;
    scanf("%d", &(item));
    *(s1->items + (s1->top)) = item;
}

void pop1(stk *s1)
{
    if (s1->top == -1)
        printf("Empty\n");
    else
    {
        printf("%d poped\n", s1->items[s1->top]);
        s1->top--;
    }
}

void push2(stk *s2, stk *s1)
{
    if (s2->top == s1->top + 1)
    {
        printf("full\n");
        return;
    }

    s2->top--;
    printf("Enter item\n");
    int item;
    scanf("%d", &(item));
    *(s2->items + (s2->top)) = item;
}

void pop2(stk *s2, stk *s1,int n)
{
    
    if (s2->top == n)
        printf("Empty\n");
    else
    {
        printf("%d poped\n", s2->items[s2->top]);
        s2->top++;
    }
}

int main()
{
    printf("Enter size of stacks\n");
    int n;
    scanf("%d", &n);
    stk s1;
    s1.top = -1;
    stk s2;
    s2.top = n;
    s1.items = (int *)malloc(sizeof(int) * n);
    s2.items=s1.items+n-1;
  //  printf("%d\n" ,(sizeof(s1)));
    int choice;
    for (;;)
    {
        printf("Enter choice\n1->push1\n2->push2\n3->pop1\n4->pop2\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push1(&s1, &s2);
            break;
        case 2:
            push2(&s2, &s1);
            break;
        case 3:
            pop1(&s1);
            break;
        case 4:
            pop2(&s2, &s1,n);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
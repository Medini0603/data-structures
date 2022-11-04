#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int *items;
    int top, size;
};
typedef struct stack STK;

void push(STK *);
void disp(STK *);
int isempty(STK *);
int isfull(STK *);
void pop(STK *);
void peek(STK *);

void main()
{
    STK s;
    s.top = -1;
    printf("Enter size of stack\n");
    scanf("%d", &s.size);
    s.items = (int *)malloc(sizeof(int) * s.size);
    int choice;
    for (;;)
    {
        printf("\nEnter your choice\n1->push\n2->display\n3->pop\n4->peek\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(&s);
            disp(&s);
            break;
        case 2:
            disp(&s);
            break;
        case 3:
            pop(&s);
            disp(&s);
            break;
        case 4:
            peek(&s);
            disp(&s);
            break;
        default:
            exit(0);
            break;
        }
    }
}
int isempty(STK *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isfull(STK *s)
{
    if (s->top == (s->size) - 1)
        return 1;
    else
        return 0;
}
void push(STK *s)
{
    if (isfull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter element to be pushed\n");
    s->top++;
    int item;
    scanf("%d", &item);
    *(s->items + s->top) = item;
}

void disp(STK *s)
{
    if (isempty(s))
    {
        printf("Stack underflow\n");
        return;
    }
    printf("THE ELEMENTS OF STACK ARE\n");
    int i = s->top;
    for (; i >= 0; i--)
        printf("%d\t", *(s->items + i));
}

void pop(STK *s)
{
    if (isempty(s))
    {
        printf("Stack underflow\n");
        return;
    }
    printf("%d is poped\n", *(s->items + s->top));
    s->top--;
}

void peek(STK *s)
{
    if (isempty(s))
    {
        printf("Stack underflow\n");
        return;
    }
    printf("The current element at the top is %d\n", *(s->items + s->top));
}

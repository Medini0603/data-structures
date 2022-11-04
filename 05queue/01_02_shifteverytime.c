#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct queue
{
    int items[size];
    int f, r;
} QUE;

void insert(QUE *Q)
{
    if (Q->r == size - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    printf("Enter item\n");
    (Q->r)++;
    scanf("%d", &(Q->items[Q->r]));
}

void disp(QUE *Q)
{
    if (Q->f > Q->r)
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = Q->f; i <= Q->r; i++)
        printf("%d \t", Q->items[i]);
}

void delete (QUE *Q)
{
    if (Q->f > Q->r)
    {
        printf("Empty queue\n");
        return;
    }

    printf("%d deleted\n", Q->items[Q->f]);
    for (int i =/* Q->f*/0; i <= Q->r; i++)
        Q->items[i] = Q->items[i + 1];
    Q->r--;
    if (Q->f > Q->r)
    {
        Q->f = 0;
        Q->r = -1;
    }
}
int main()
{
    QUE Q;
    Q.f = 0;
    Q.r = -1;
    int choice;
    for (;;)
    {
        printf("\nEnter choice\n1->insert\n2->display\n3->delete\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(&Q);
            disp(&Q);
            break;
        case 2:
            disp(&Q);
            break;
        case 3:
            delete (&Q);
            disp(&Q);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
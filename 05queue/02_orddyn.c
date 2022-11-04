#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *items;
    int f, r, size;
} QUE;

void insert(QUE *q)
{
    if (q->r == q->size - 1)
    {
        printf("Queue full\n");
        return;
    }

    q->r++;
    int item;
    printf("Enter item\n");
    scanf("%d", &item);
    q->items[q->r] = item;
}

void delete (QUE *q)
{
    if (q->f > q->r)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Deleted %d\n", q->items[q->f]);
    q->f++;

    if (q->f > q->r)
    {
        q->f = 0;
        q->r = -1;
    }
}

void disp(QUE *q)
{
    if (q->f > q->r)
    {
        printf("Queue empty\n");
        return;
    }

    int i;
    for (i = q->f; i <= q->r; i++)
        printf("%d\t", q->items[i]);
    printf("\n");
}

void main()
{
    QUE q;
    q.f = 0;
    q.r = -1;
    printf("Enter size of queue\n");
    scanf("%d", &q.size);
    q.items = (int *)malloc(sizeof(int) * q.size);

    int choice;
    for (;;)
    {
        printf("Enter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(&q);
            disp(&q);
            break;
        case 2:
            disp(&q);
            break;
        case 3:
            delete (&q);
            disp(&q);
            break;
        default:
            exit(0);
            break;
        }
    }
}

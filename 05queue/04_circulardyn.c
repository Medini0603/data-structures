#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *items;
    int f, r, cnt, size;
} QUE;

void insert(QUE *q)
{
    if (q->cnt == q->size)
    {
        printf("Queue full\n");
        return;
    }

    q->r = (q->r + 1) % q->size;
    int item;
    printf("Enter item\n");
    scanf("%d", &item);
    *(q->items + q->r) = item;
    q->cnt++;
}

void delete (QUE *q)
{
    if (q->cnt == 0)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Deleted %d\n", *(q->items + q->f));
    q->f = (q->f + 1) % q->size;
    q->cnt--;

    /*if(q->f>q->r)
    {
    q->f=0;
    q->r=-1;
    }*/
}

void disp(QUE *q)
{
    if (q->cnt == 0)
    {
        printf("Queue empty\n");
        return;
    }

    int i;
    int j = q->f;
    for (i = 1; i <= q->cnt; i++)
    {
        printf("%d\t", *(q->items + j));
        j = (j + 1) % (q->size);
    }
    printf("\n");
}

void main()
{
    QUE q;
    q.f = 0;
    q.r = -1;
    q.cnt = 0;
    printf("Enter size\n");
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

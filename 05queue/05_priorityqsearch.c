#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct q
{
    int items[size];
    int f, r;
} QUE;

void insert(QUE *q)
{
    if (q->r == size - 1)
    {
        printf("FULL\n");
        return;
    }

    printf("Enter item\n");
    scanf("%d", &q->items[++q->r]);
}

void disp(QUE *q)
{
    for (int i = q->f; i <= q->r; i++)
        printf("%d  ", q->items[i]);
    printf("\n");
}

void aspri(QUE *q)
{
    if (q->f > q->r)
    {
        printf("Empty\n");
        return;
    }
    int min = q->items[0];
    int pos = 0;
    for (int i = 0; i <= q->r; i++)
    {
        if (q->items[i] < min)
        {
            min = q->items[i];
            pos = i;
        }
    }
    printf("%d deleted\n", q->items[pos]);
    for (int i = pos; i < q->r; i++)
    {
        q->items[i] = q->items[i + 1];
    }
    q->r = q->r - 1;
    if (q->f > q->r)
    {
        q->f = 0;
        q->r = -1;
    }
}

void despri(QUE *q)
{
    if (q->f > q->r)
    {
        printf("Empty\n");
        return;
    }
    int max = q->items[0];
    int pos = 0;
    for (int i = 0; i <= q->r; i++)
    {
        if (q->items[i] > max)
        {
            max = q->items[i];
            pos = i;
        }
    }
    printf("%d deleted\n", q->items[pos]);
    for (int i = pos; i < q->r; i++)
    {
        q->items[i] = q->items[i + 1];
    }
    q->r = q->r - 1;
    if (q->f > q->r)
    {
        q->f = 0;
        q->r = -1;
    }
}
int main()
{
    QUE q;
    q.f = 0;
    q.r = -1;
    int choice;
    for (;;)
    {
        printf("\nEnter choice\n1->insert\n2->disp\n3->aspri\n4->despre\n");
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
            aspri(&q);
            disp(&q);
            break;

        case 4:
            despri(&q);
            disp(&q);
            break;
        }
    }
    return 0;
}
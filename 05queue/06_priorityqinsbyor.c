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
    int item;
    scanf("%d", &item);
    int i;
    if (q->r == -1 && q->f == 0)
    {
        q->r++;
        q->items[q->r] = item;
        return;
    }
    for (i = q->r; i >= q->f && item < q->items[i]; i--)
        q->items[i + 1] = q->items[i];
    q->items[i + 1] = item;
    q->r++;
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
    printf("%d deleted\n", q->items[q->f++]);
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
    printf("%d deleted\n", q->items[q->r--]);
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
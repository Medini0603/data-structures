#include <stdio.h>
#include <stdlib.h>
#define size 3

typedef struct job
{
    int pri;
    int id;
    char name[10];
} JOB;

typedef struct q
{
    JOB items[size];
    int f, r;
} QUE;

void insert(QUE *q)
{
    if (q->r == size - 1)
    {
        printf("FULL\n");
        return;
    }
    printf("Enter job details\n");
    JOB s,*j;
    j=&s;
    printf("Enter id\n");
    scanf("%d", &j->id);
    printf("Enter name\n");
    scanf("%s", j->name);
    printf("Enter priority\n");
    scanf("%d", &j->pri);
    int i;
    if (q->r == -1 && q->f == 0)
    {
        q->r++;
        q->items[q->r] = *j;
        return;
    }
    for (i = q->r; i >= q->f && j->pri < q->items[i].pri; i--)
        q->items[i + 1] = q->items[i];
    q->items[i + 1] = *j;
    q->r++;
}

void disp(QUE *q)
{
    for (int i = q->f; i <= q->r; i++)
    {
        printf("id :  ");
        printf("%d\n", q->items[i].id);
        printf("name :  ");
        printf("%s\n", q->items[i].name);
        printf("priority :  ");
        printf("%d\n", q->items[i].pri);
    }
    printf("\n");
}

void aspri(QUE *q)
{
    if (q->f > q->r)
    {
        printf("Empty\n");
        return;
    }
    printf("%d deleted\n", q->items[q->f++].pri);
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
    printf("%d deleted\n", q->items[q->r--].pri);
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
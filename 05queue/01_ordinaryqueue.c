#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct queue
{
    int items[size];
    int f, r;
    //int flag;
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
  //  Q->flag = 1;
    // int item;
    scanf("%d", &(Q->items[Q->r]));
    // (Q->items[Q->r]);
}

void disp(QUE *Q)
{
    if (Q->f > Q->r/* || Q->flag == 0*/)
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
    Q->f++;

    if (Q->f > Q->r)
    {
        Q->f = 0;
        Q->r =- 1;
        //Q->flag = 0;
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
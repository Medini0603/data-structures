#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct queue
{
    int items[size];
    int f, r;
} QUE;

void insertrear(QUE *Q)
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

void insertfront(QUE *Q)
{
  /*  if (Q->r == size - 1)
    {
        printf("Queue is Full\n");
        return;
    }*/

    printf("Enter item\n");
    int item;
    scanf("%d", &item);

    if(Q->r==-1 &&Q->f==0)
    {
        Q->items[++Q->r]=item;
        return;
    }

    if(Q->f!=0)
        Q->items[--Q->f]=item;
    else
        printf("Insertion not possible\n");
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

void deletefront(QUE *Q)
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
        Q->r = -1;
    }
}
void deleterear(QUE *Q)
{
    if (Q->f > Q->r)
    {
        printf("Empty queue\n");
        return;
    }

    printf("%d deleted\n", Q->items[Q->r]);
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
        printf("\nEnter choice\n1->insertrear\n2->display\n3->deletefront\n4->insertfront\n5->deleterear\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertrear(&Q);
            disp(&Q);
            break;
        case 2:
            disp(&Q);
            break;
        case 3:
            deletefront(&Q);
            disp(&Q);
            break;

        case 4:
            insertfront(&Q);
            disp(&Q);
            break;

        case 5:
            deleterear(&Q);
            disp(&Q);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
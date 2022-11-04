#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int items;
    struct queue *link;
};
typedef struct queue *QUE;

QUE createnode()
{
    QUE nn = (QUE)malloc(sizeof(struct queue));
    printf("Enter info\n");
    scanf("%d", &nn->items);
    nn->link = NULL;
    return nn;
}
QUE enque(QUE q)
{
    QUE nn = createnode();
    if (q == NULL)
        q = nn;
    else
        nn->link = q->link;
    q->link = nn;
    return nn;
}

void disp(QUE q)
{
    if (q == NULL)
    {
        printf("Queue empty\n");
        return;
    }
    QUE temp = q->link;
    do
    {
        printf("%d\t", temp->items);
        temp = temp->link;
    } while (temp != q->link);
}

QUE deque(QUE q)
{
    if (q == NULL)
    {
        printf("Queue empty\n");
        return NULL;
    }

    QUE nd = q->link;
    if (nd == q)
        q = NULL;
    else
        q->link = nd->link;
    printf("%d removed from queue\n",nd->items);
    free(nd);
    return q;
}
int main()
{
    QUE q;
    q = NULL;
    int choice;
    for (;;)
    {
        printf("\nEnter choice\n1->enqueue\n2->display\n3->deque\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            q = enque(q);
            disp(q);
            break;
        case 2:
            disp(q);
            break;
         case 3:
            q = deque(q);
            disp(q);
            break;
        }
    }
    return 0;
}
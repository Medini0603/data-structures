#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int info;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE createnode()
{
    NODE nn = (NODE)malloc(sizeof(struct node));
    printf("Enter node info\n");
    scanf("%d", &nn->info);
    nn->llink = nn->rlink = NULL;
    return nn;
}

NODE insert(NODE root)
{
    NODE nn = createnode();
    char str[10];
    NODE pn, tp;
    int i;
    if (root == NULL)
        return nn;
    printf("Enter the direction\n");
    scanf("%s", str);
    pn = NULL;
    tp = root;
    for (i = 0; i < strlen(str); i++)
    {
        // pn=NULL;tp=root;
        if (tp == NULL)
            break;
        pn = tp;
        if (str[i] == 'L' || str[i] == 'l')
            tp = tp->llink;
        else
            tp = tp->rlink;
    }

    if (tp != NULL)
    {
        printf("Insertion not possible\n");
        return root;
    }
    if (strlen(str) != i)
    {
        printf("Invalid direction\n");
        return root;
    }

    if (str[i - 1] == 'l' || str[i - 1] == 'L')
        pn->llink = nn;
    else
        pn->rlink = nn;
    return root;
}

typedef struct queue
{
    NODE items[20];
    int r, f;
} QUE;

void enque(QUE *q, NODE n)
{
    q->items[++q->r] = n;
}

void deque(QUE *q)
{
    printf("%d\t", q->items[q->f++]->info);
}

void bfd(NODE root)
{
    QUE q;
    q.f = 0;
    q.r = -1;

    enque(&q, root);
    while (q.f <= q.r)
    {
        if (root->llink != NULL)
            enque(&q, root->llink);
        if (root->rlink != NULL)
            enque(&q, root->rlink);
        deque(&q);
        root = q.items[q.f];
    }
}

int main()
{
    NODE root = NULL;
    int choice;
    for (;;)
    {
        printf("\nEnter choice\n1->insert\n2->display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = insert(root);
            break;
        case 2:
            bfd(root);
            break;
        }
    }
    return 0;
}
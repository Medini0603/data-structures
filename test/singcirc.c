#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

void insertrear(NODE h)
{
    NODE nn = (NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    scanf("%d", &nn->info);
    //  h->info++;
    if (h->info == 0)
    {
        h->info++;
        h->link = nn;
        nn->link = nn;
        return;
    }
    h->info++;
    nn->link = h->link->link;
    h->link->link = nn;
    h->link = nn;
}

void disp(NODE h)
{
    if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }
    NODE tp = h->link->link;
    do
    {
        printf("%d\t", tp->info);
        tp = tp->link;
    } while (tp != h->link->link);
}

void deleteprec(NODE h)
{
    int k;
    printf("Enter k\n");
    scanf("%d", &k);
    NODE pn = NULL;
    NODE nd = h->link->link;
    int cnt = 1;
    do
    {
        if (cnt == k - 1)
            break;

        else
        {
            pn = nd;
            nd = nd->link;
            cnt++;
        }
    } while (nd != h->link->link);

    if (k == 1||k>h->info)
    {
        printf("No deletion possible\n");
        return;
    }

    if (nd == h->link->link && pn == NULL)
    {
        h->link->link = nd->link;
    }
    else
        pn->link = nd->link;
    printf("Deleted %d\n", nd->info);
    h->info--;
    free(nd);
}

int main()
{
    NODE header = (NODE)malloc(sizeof(struct node));
    header->info = 0;
    header->link = NULL;
    int choice;
    for (;;)
    {
        printf("\nEnter choice\n1->insertrear\n2->disp\n3->delete\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertrear(header);
            disp(header);
            break;
        case 2:
            disp(header);
            break;

        case 3:
            deleteprec(header);
            disp(header);
            break;
        }
    }
    return 0;
}
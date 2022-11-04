#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE createnode()
{
    NODE nn = (NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    scanf("%d", &nn->info);
    nn->link = NULL;
    return nn;
}
void insertfront(NODE h)
{
    NODE nn = createnode();
    if (h->info == 0)
        h->link = nn;
    // h->link->link = nn;
    else
        nn->link = h->link->link;
    h->link->link = nn;
    h->info++;
}

void disp(NODE h)
{
    if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }
    NODE temp = h->link->link;
    do
    {
        printf("%d\t", temp->info);
        temp = temp->link;
    } while (temp != h->link->link);
}

void insertrear(NODE h)
{
    NODE nn = createnode();
    if (h->info == 0)
    {
        h->link = nn;
        nn->link = h->link;
    }

    else
    {
        nn->link = h->link->link;
        h->link->link = nn;
        h->link = nn;
    }

    h->info++;
}

void deletefront(NODE h)
{
    if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }

    NODE nd = h->link->link;
    printf("%d deleted\n", nd->info);
    if (nd == h->link)
        h->link = NULL;
    else
        h->link->link = nd->link;
    free(nd);
    h->info--;
}

void deleterear(NODE h)
{
    if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }

    NODE nd = h->link;
    printf("%d deleted\n", nd->info);
    NODE pp = h->link->link;
    while (pp->link != nd)
        pp = pp->link;

    if (nd == h->link->link)
        h->link = NULL;
    else
    {
        pp->link = nd->link;
        h->link = pp;
    }
    h->info--;
    free(nd);
}

NODE search(NODE h)
{
    if (h->info == 0)
    {
        printf("Empty\n");
        return NULL;
    }
    int key;
    printf("Enter key\n");
    scanf("%d", &key);

    NODE tp = h->link->link;
    int pos = 1;
    do
    {
        if (tp->info == key)
        {
            printf("NODE found at %d\n", pos);
            return tp;
        }

        tp = tp->link;
        pos++;
    } while (tp != h->link->link);

    return NULL;
}

void sort(NODE h)
{
    int n = h->info;

    NODE tp = h->link->link;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tp->info > tp->link->info)
            {
                int temp = tp->info;
                tp->info = tp->link->info;
                tp->link->info = temp;
            }
            tp = tp->link;
        }
        tp = h->link->link;
    }
}

void insertbyorder(NODE h)
{
    NODE nn = createnode();
    h->info++;
    if (h->link == NULL)
    {
        h->link = nn;
        h->link->link = nn;
        return;
    }
    sort(h);
    NODE fp = h->link->link;
    NODE pp = NULL;
    do
    {
        if (fp->info > nn->info)
            break;
        pp = fp;
        fp = fp->link;
    } while (fp != h->link->link);

    if (pp == NULL)
    {
        nn->link = fp;
        h->link->link = nn;
        return;
    }

    if (fp == h->link->link)
    {
        nn->link = fp;
        h->link->link = nn;
        h->link = nn;
        return;
    }

    nn->link = fp;
    pp->link = nn;
}

void deletebyelem(NODE h)
{
    if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }

    printf("Enter the element to be deleted\n");
    int key;
    scanf("%d", &key);
    NODE nd = NULL;
    NODE pp = NULL;
    NODE fp = h->link->link;

    do
    {
        if (key == fp->info)
        {
            nd = fp;
            printf("%d deleted\n", nd->info);
            break;
        }

        pp = fp;
        fp = fp->link;
    } while (fp != h->link->link);

    if (nd == NULL)
    {
        printf("Not found\nNo deletion\n");
        return;
    }

    if (pp == NULL && nd == h->link)
    {
        h->link = NULL;
        free(nd);
        h->info--;
        return;
    }
    if (pp == NULL)
        h->link->link = nd->link;
    else if (nd == h->link)
    {
        pp->link = nd->link;
        h->link = pp;
    }

    else
        pp->link = nd->link;
    free(nd);
    h->info--;
}

void reverse(NODE h)
{
    NODE fp = h->link->link;
    NODE temp = h->link->link;
    NODE lp = h->link;
    NODE tp = h->link;

    do
    {
        lp = fp;
        fp = fp->link;
        lp->link = tp;
        tp = lp;
    } while (fp != temp);

    h->link = fp; // IMP!!!!!!!
}

void insbypos(NODE h)
{
    NODE nn = createnode();

    int pos;
    printf("Enter position\n");
    scanf("%d", &pos);

    if (h->link == NULL)
    {
        if (pos == 1)
        {
            h->info++;
            h->link = nn;
            nn->link = nn;
        }
        else
        {
            printf("Invalid position\n");
        }
        return;
    }
    int cnt = 1;
    NODE fp = h->link->link;
    NODE pp = NULL;

    do
    {
        if (cnt == pos)
            break;

        pp = fp;
        fp = fp->link;
        cnt++;
    } while (fp != h->link->link);

    if (cnt != pos)
    {
        printf("Invalid position\n");
        return;
    }
    h->info++;

    if (pp == NULL)
    {
        nn->link = h->link->link;
        h->link->link = nn;
        return;
    }

    if (fp == h->link->link)
    {
        nn->link = h->link->link;
        h->link->link = nn;
        h->link = nn;
        return;
    }

    pp->link = nn;
    nn->link = fp;
}

void delbypos(NODE h)
{
    if (h->link == NULL)
    {
        printf("Empty\n");
        return;
    }
    int pos;
    printf("Enter position\n");
    scanf("%d", &pos);

    NODE nd = h->link->link;
    NODE pn = NULL;
    int cnt = 1;
    do
    {
        if (cnt == pos)
            break;
        pn = nd;
        nd = nd->link;
        cnt++;
    } while (pn != h->link);

    if (pn == h->link)
    {
        printf("Invalid position\n");
        return;
    }
    h->info--;
    printf("%d deleted\n", nd->info);
    if (nd == h->link && nd == h->link->link)
    {
        h->link = NULL;
        free(nd);
        return;
    }
    if (pn == NULL)
    {
        h->link->link = nd->link;
        free(nd);
        return;
    }

    if (nd == h->link)
    {
        pn->link = h->link->link;
        h->link = pn;
    }

    else
    {
        pn->link = nd->link;
    }

    free(nd);
}

NODE copy(NODE h)
{
    NODE c = (NODE)malloc(sizeof(struct node));
    c->info = 0;
    c->link = NULL;
    NODE temp = h->link->link;

    do
    {
        NODE nn = (NODE)malloc(sizeof(struct node));
        nn->info = temp->info;
        if (c->link == NULL)
        {
            c->link = nn;
            nn->link = c->link;
        }
        else
        {
            nn->link = c->link->link;
            c->link->link = nn;
            c->link = nn;
        }
        c->info++;
        temp = temp->link;
    } while (temp != h->link->link);
    return c;
}
int main()
{
    NODE header = (NODE)malloc(sizeof(struct node));
    header->info = 0;
    header->link = NULL;

    NODE ns = NULL;
    int choice;
    NODE c = NULL;
    for (;;)
    {
        printf("\nEnter choice\n1->insertfront\n2->display\n3->insertrear\n4->deletefront\n5->deleterear\n6->search\n7->sort\n8->insertbyorder\n9->deletebyelem\n10->reverse\n11->insertbypos\n12->deletebypos\n13->copy\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertfront(header);
            disp(header);
            break;
        case 2:
            disp(header);
            break;
        case 3:
            insertrear(header);
            disp(header);
            break;
        case 4:
            deletefront(header);
            disp(header);
            break;
        case 5:
            deleterear(header);
            disp(header);
            break;
        case 6:
            ns = search(header);
            if (ns == NULL)
            {
                printf("Node not found\n");
            }
            break;
        case 7:
            sort(header);
            disp(header);
            break;
        case 8:
            insertbyorder(header);
            disp(header);
            break;
        case 9:
            deletebyelem(header);
            disp(header);
            break;
        case 10:
            reverse(header);
            disp(header);
            break;
        case 11:
            insbypos(header);
            disp(header);
            break;
        case 12:
            delbypos(header);
            disp(header);
            break;
        case 13:
            c = copy(header);
            disp(header);
            printf("\n");
            disp(c);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
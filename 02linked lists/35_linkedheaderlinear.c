#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE createnode(NODE nn);
void insertfront(NODE h);
void disp(NODE h);
void insertrear(NODE h);
void deletefront(NODE h);
void deleterear(NODE h);
void insertbyorder(NODE h);
void deletebyelem(NODE h);
void insertbypos(NODE h);
void deletebypos(NODE h);
NODE search(NODE h);
void sort(NODE h);
void reverse(NODE h);

int main()
{
    NODE header = NULL;
    header = (NODE)malloc(sizeof(struct node));
    header->info = 0;
    header->link = NULL;

    NODE SN = NULL;
    int choice;
    for (;;)
    {
        printf("\nEnter choice\n1->insertfront\n2->display\n3->insertrear\n4->deletefront\n5->deleterear\n6->insertbyorder\n7->deletebyelement\n8->insertbypos\n9->deletebypos\n10->search\n11->sort\n12->reverse\n");
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
            sort(header);
            insertbyorder(header);
            disp(header);
            break;

        case 7:
            deletebyelem(header);
            disp(header);
            break;

        case 8:
            insertbypos(header);
            disp(header);
            break;

        case 9:
            deletebypos(header);
            disp(header);
            break;

        case 10:
            SN = search(header);
            if (SN == NULL)
            {
                printf("Node not found");
            }
            else
            {
                printf("Node found with the info %d", SN->info);
            }
            break;

        case 11:
            sort(header);
            disp(header);
            break;

        case 12:
            reverse(header);
            disp(header);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}

NODE createnode(NODE nn)
{
    nn = (NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    scanf("%d", &nn->info);
    nn->link = NULL;
    return nn;
}

void insertfront(NODE h)
{
    NODE nn = NULL;
    nn = createnode(nn);
    nn->link = h->link;
    h->link = nn;
    h->info++;
}

void disp(NODE h)
{
    if (h->link == NULL)
    {
        printf("Empty\n");
        return;
    }
    NODE fp = h->link;
    while (fp != NULL)
    {
        printf("%d\t", fp->info);
        fp = fp->link;
    }
}

void insertrear(NODE h)
{
    NODE nn = createnode(nn);
    NODE lp = h;
    while (lp->link != NULL)
    {
        lp = lp->link;
    }
    lp->link = nn;
    h->info++;
}

void deletefront(NODE h)
{
    if (h->link == NULL)
    {
        printf("Empty\n");
        return;
    }

    NODE nd = h->link;
    h->link = nd->link;
    printf("%d deleted\n", nd->info);
    free(nd);
    h->info--;
}

void deleterear(NODE h)
{
    if (h->link == NULL)
    {
        printf("Empty\n");
        return;
    }
    NODE nd = h->link;
    NODE pp = h;
    while (pp->link->link != NULL)
    {
        pp = nd;
        nd = nd->link;
    }

    pp->link = NULL;
    printf("%d deleted\n", nd->info);
    free(nd);
    h->info--;
}

void insertbyorder(NODE h)
{
    NODE nn = createnode(nn);
    NODE pp = h;
    NODE f = h->link;

    while (f != NULL && nn->info > f->info)
    {
        pp = f;
        f = f->link;
    }
    pp->link = nn;
    nn->link = f;
    h->info++;
}

void deletebyelem(NODE h)
{
    if (h == NULL)
    {
        printf("Empty\n");
        return;
    }

    int elem;
    printf("Enter the element to be deleted\n");
    scanf("%d", &elem);
    NODE nd = h->link;
    NODE pp = h;

    while (nd != NULL && nd->info != elem)
    {
        pp = nd;
        nd = nd->link;
    }

    if (nd == NULL)
    {
        printf("not found\n");
        return;
    }

    pp->link = nd->link;
    printf("%d deleted\n", nd->info);
    free(nd);
    h->info--;
}

void insertbypos(NODE h)
{
    int pos;
    printf("Enter position\n");
    scanf("%d", &pos);
    NODE nn = createnode(nn);
    NODE pp = h;
    NODE fp = h->link;
    int cnt = 1;
    while (fp != NULL && cnt != pos)
    {
        pp = fp;
        fp = fp->link;
        cnt++;
    }

    if (cnt != pos)
    {
        printf("Invalid position\n");
        return;
    }

    pp->link = nn;
    nn->link = fp;
    h->info++;
}

void deletebypos(NODE h)
{
    if (h->link == NULL)
    {
        printf("Empty\n");
        return;
    }
    printf("Enter position\n");
    int pos;
    scanf("%d", &pos);

    int cnt = 1;
    NODE nd = h->link;
    NODE pp = h;

    while (nd->link != NULL && pos != cnt)
    {
        pp = nd;
        nd = nd->link;
        cnt++;
    }

    if (pos != cnt)
    {
        printf("Invalid position\n");
        return;
    }
    pp->link = nd->link;
    printf("%d is deleted\n", nd->info);
    free(nd);
    h->info--;
}

NODE search(NODE h)
{
    int key;
    printf("Enter key to be searched\n");
    scanf("%d", &key);

    if (h->link == NULL)
    {
        printf("Empty\n");
        return NULL;
    }
    NODE fp = h->link;
    int pos = 1;
    while (fp != NULL)
    {
        if (fp->info == key)
        {
            printf("%d found at %d\n", key, pos);
            return fp;
            break;
        }

        fp = fp->link;
        pos++;
    }
    return NULL;
}

void sort(NODE h)
{
    if (h->link == NULL)
    {
        printf("Empty\n");
        return;
    }

    NODE fp = h->link;
    int n = h->info;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (fp->info > fp->link->info)
            {
                int temp = fp->info;
                fp->info = fp->link->info;
                fp->link->info = temp;
            }
            fp = fp->link;
        }
        fp = h->link;
    }
}

void reverse(NODE h)
{
    if(h->link==NULL)
    {
        printf("Empty\n");
        return;
    }
    NODE fp=h->link;
    NODE lp=NULL;
    NODE tp=NULL;
    while(fp!=NULL)
    {
        lp=fp;
        fp=fp->link;
        lp->link=tp;
        tp=lp;
    }

    h->link=lp;
}
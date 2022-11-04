#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
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
void reverseprint(NODE h);

int main()
{
    NODE header = NULL;
    header = (NODE)malloc(sizeof(struct node));
    header->info = 0;
    header->llink = header;
    header->rlink = header;

    NODE SN = NULL;
    int choice;
    for (;;)
    {
        printf("\nEnter choice\n1->insertfront\n2->display\n3->insertrear\n4->deletefront\n5->deleterear\n6->insertbyorder\n7->deletebyelement\n8->insertbypos\n9->deletebypos\n10->search\n11->sort\n12->reverse\n13->reversedisplay\n");
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

        case 13:
            reverseprint(header);
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
    nn->llink = NULL;
    nn->rlink = NULL;
    return nn;
}

void insertfront(NODE h)
{
    NODE nn = NULL;
    nn = createnode(nn);
    nn->rlink = h->rlink;
    nn->llink = h;
    h->rlink->llink = nn;
    h->rlink = nn;
    h->info++;
}

void disp(NODE h)
{
    if (h->llink == h)
    {
        printf("Empty\n");
        return;
    }
    NODE fp = h->rlink;
    while (fp != h)
    {
        printf("%d\t", fp->info);
        fp = fp->rlink;
    }
}

void insertrear(NODE h)
{
    NODE nn = createnode(nn);
    NODE lp = h;
    nn->rlink = h;
    nn->llink = h->llink;
    h->llink->rlink = nn;
    h->llink = nn;
    h->info++;
}

void deletefront(NODE h)
{
    if (h->llink == h)
    {
        printf("Empty\n");
        return;
    }

    NODE nd = h->rlink;
    h->rlink = nd->rlink;
    nd->rlink->llink = h;
    printf("%d deleted\n", nd->info);
    free(nd);
    h->info--;
}

void deleterear(NODE h)
{
    if (h->llink == h)
    {
        printf("Empty\n");
        return;
    }
    NODE nd = h->llink;
    h->llink = nd->llink;
    /**/ nd->llink->rlink = h; // observe carefully
    printf("%d deleted\n", nd->info);
    free(nd);
    h->info--;
}

void insertbyorder(NODE h)
{
    NODE nn = createnode(nn);
    NODE fp = h->rlink;

    while (fp != h && nn->info > fp->info)
    {
        fp = fp->rlink;
    }
    nn->rlink = fp;
    /**/ nn->llink = fp->llink; // observe carefully   its not nn->llink = fp->llink->rlink;---->this becomes again fp only
    fp->llink->rlink = nn;
    fp->llink = nn;
    h->info++;
}

void deletebyelem(NODE h)
{
    if (h->llink == h)
    {
        printf("Empty\n");
        return;
    }

    int elem;
    printf("Enter the element to be deleted\n");
    scanf("%d", &elem);
    NODE nd = h->rlink;
    while (nd != h && nd->info != elem)
    {
        nd = nd->rlink;
    }
    if (nd == h)
    {
        printf("Not found\n");
        return;
    }
    nd->llink->rlink = nd->rlink;
    nd->rlink->llink = nd->llink;
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

    int cnt = 1;
    NODE fp = h->rlink;
    while (fp != h && cnt != pos)
    {
        fp = fp->rlink;
        cnt++;
    }
    if (cnt != pos)
    {
        printf("Invalid position\n");
        return;
    }
    nn->rlink = fp;
    nn->llink = fp->llink;
    fp->llink->rlink = nn;
    fp->llink = nn;

    h->info++;
}

void deletebypos(NODE h)
{
    if (h->llink == h)
    {
        printf("Empty\n");
        return;
    }
    printf("Enter position\n");
    int pos;
    scanf("%d", &pos);

    int cnt = 1;
    NODE nd = h->rlink;
    while (nd != h && cnt != pos)
    {
        nd = nd->rlink;
        cnt++;
    }
    // if (pos != cnt)
    // {
    //     printf("Invalid position\n");
    //     return;
    // }-------------->its wrong leads to infinite loop if we give pos as number of elements +1
    if (nd == h || cnt != pos)
    {
        printf("Invalid position\n");
        return;
    }
    nd->llink->rlink = nd->rlink;
    nd->rlink->llink = nd->llink;
    printf("%d is deleted\n", nd->info);
    free(nd);
    h->info--;
}

NODE search(NODE h)
{
    int key;
    printf("Enter key to be searched\n");
    scanf("%d", &key);

    if (h->llink == h)
    {
        printf("Empty\n");
        return NULL;
    }
    NODE fp = h->rlink;
    int pos = 1;
    while (fp != h)
    {
        if (fp->info == key)
        {
            printf("%d found at %d\n", key, pos);
            return fp;
            break;
        }

        fp = fp->rlink;
        pos++;
    }
    return NULL;
}

void sort(NODE h)
{
    if (h->llink == h)
    {
        printf("Empty\n");
        return;
    }

    NODE fp = h->rlink;
    int n = h->info;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (fp->info > fp->rlink->info)
            {
                int temp = fp->info;
                fp->info = fp->rlink->info;
                fp->rlink->info = temp;
            }
            fp = fp->rlink;
        }
        fp = h->rlink;
    }
}

void reverse(NODE h)
{
    int n = h->info;
    NODE fp = h->rlink;
    NODE lp = h->llink;
    for (int i = 1; i <= n / 2; i++)
    {
        int temp = fp->info;
        fp->info = lp->info;
        lp->info = temp;

        fp = fp->rlink;
        lp = lp->llink;
    }
}

void reverseprint(NODE h)
{
    NODE lp = h->llink;
    while (lp != h)
    {
        printf("%d\t", lp->info);
        lp = lp->llink;
    }
}
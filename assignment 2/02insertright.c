// Write a function called INSERT(PH, K) where PH is a pointer to Header node in a non-empty  circular double linked list of integers with Header and K is an integer ,
// inserts a new node as a  successor of the Kth node.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE createnode(NODE);
void insertrear(NODE);
void disp(NODE);
void insertright(NODE, int);
int main()
{
    NODE header = (NODE)malloc(sizeof(struct node));
    header->info = 0;
    header->llink = header;
    header->rlink = header;

    printf("Enter number of elements\n");
    int n;
    scanf("%d", &n);
    printf("Enter elements one by one\n");
    for (int i = 0; i < n; i++)
    {
        insertrear(header);
    }
    disp(header);

    printf("Enter position\n");
    int pos;
    scanf("%d", &pos);
    insertright(header, pos);
    disp(header);
    return 0;
}

NODE createnode(NODE nn)
{
    nn = (NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    scanf("%d", &nn->info);
    nn->llink = nn->rlink = NULL;
    return nn;
}

void insertrear(NODE h)
{
    NODE nn = createnode(nn);
    nn->rlink = h;
    nn->llink = h->llink;
    h->llink->rlink = nn;
    h->llink = nn;
    h->info++;
}

void disp(NODE h)
{
    NODE fp = h->rlink;
    while (fp != h)
    {
        printf("%d\t", fp->info);
        fp = fp->rlink;
    }
    printf("\n");
}

void insertright(NODE h, int pos)
{
    NODE nn = createnode(nn);
    NODE fp = h->rlink;
    int cnt = 1;
    while (fp != h && cnt != pos)
    {
        fp = fp->rlink;
        cnt++;
    }

    if (cnt != pos || fp==h)
    {
        printf("Invalid position\n");
        return;
    }

    nn->llink = fp;
    nn->rlink = fp->rlink;
    fp->rlink->llink = nn;
    fp->rlink = nn;
    h->info++;
}
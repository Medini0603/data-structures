// Write a function called SWAP(N1,N2) where N1 and N2 are pointers to two different nodes  in a non-empty(with more than 1 nodes)
//  circular double linked list of integers with Header
//,  swaps N1 and N2 without creating temporary nodes .
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
void swap(NODE, NODE, NODE);
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
    NODE n1 = header->rlink->rlink;
    NODE n2 = header->llink->llink->llink->llink;
    swap(header, n1, n2);
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

void swap(NODE h, NODE n1, NODE n2)
{
    NODE pn2 = n2->llink;
    NODE nn2 = n2->rlink;
    
    n2->llink->rlink = n1;
    n2->rlink->llink = n1;
    n1->llink->rlink = n2;
    n1->rlink->llink = n2;

    n2->llink = n1->llink;
    n2->rlink = n1->rlink;
    n1->rlink = nn2;
    n1->llink = pn2;
}
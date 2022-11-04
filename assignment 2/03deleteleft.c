// Write a function called DELETE(PH, K) where PH is a pointer to Header node in a non-empty  circular double linked list of integers with Header and K is an integer , 
//deletes predecessor of  the Kth node(if it is not Header). 
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
void deleteleft(NODE, int);
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
    deleteleft(header, pos);
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

void deleteleft(NODE h, int pos)
{
    NODE fp = h->rlink;
    int cnt = 1;
    while (fp != h && cnt != pos)
    {
        fp = fp->rlink;
        cnt++;
    }
   NODE nd=fp->llink;
    if (cnt != pos || nd==h)
    {
        printf("Invalid position\nor header cant be deleted\n");
        return;
    }

   nd->llink->rlink=nd->rlink;
   nd->rlink->llink=nd->llink;
   h->info--;
   printf("%d deleted\n",nd->info);
   free(nd);
}
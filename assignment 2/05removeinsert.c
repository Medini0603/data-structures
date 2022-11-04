//Write a function called REMOVEINSERT(PH) where PH is a pointer to Header node 
//in a non empty circular double linked list of integers with Header , 
//removes the last node and inserts  to the beginning of the list. 

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
void removeinsert(NODE);
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
    int choice;
for(;;)
{
    printf("Enter 1 for removeinsert\n");
    scanf("%d",&choice);
    if(choice==1)
    {removeinsert(header);
    disp(header);}
    else exit(0);
}
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

void removeinsert(NODE h)
{
   NODE l=h->llink;
   l->llink->rlink=h;
   NODE t=l->llink;
   l->llink=h;
   l->rlink=h->rlink;
   h->rlink->llink=l;
   h->rlink=l;
   h->llink=t;
}
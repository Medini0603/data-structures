// Write a function called MERGE which merges two sorted lists 
//in to a single sorted list(Single  or Double) 
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
void mergesort(NODE,NODE);
int main()
{
    NODE header = (NODE)malloc(sizeof(struct node));
    header->info = 0;
    header->llink = header;
    header->rlink = header;

     NODE h = (NODE)malloc(sizeof(struct node));
    h->info = 0;
    h->llink = h;
    h->rlink = h;

    printf("Enter number of elements in list one\n");
    int n;
    scanf("%d", &n);
    printf("Enter elements one by one\n");
    for (int i = 0; i < n; i++)
    {
        insertrear(header);
    }
     
    disp(header);

     printf("Enter number of elements in 2\n");
    int n2;
    scanf("%d", &n2);
    printf("Enter elements one by one\n");
    for (int i = 0; i < n2; i++)
    {
        insertrear(h);
    }
    disp(h);

    mergesort(header,h);
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

void mergesort(NODE h1,NODE h2)
{
    h1->llink->rlink=h2->rlink;
    h2->rlink->llink=h1->llink;
    h2->llink->rlink=h1;
    h1->llink=h2->llink;
NODE f=h1->rlink;
int n=h1->info+h2->info;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(f->info>f->rlink->info)
            {
                int temp=f->info;
                f->info=f->rlink->info;
                f->rlink->info=temp;
            }
            f=f->rlink;
        }
        f=h1->rlink;
    }
}
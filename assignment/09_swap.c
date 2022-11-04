#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * link;
};
typedef struct node * NODE;

NODE insert(NODE);
void disp(NODE);
NODE swap(NODE,NODE,NODE);

int main(){
    NODE f=NULL;
    for(int i=0;i<10;i++)
    {
        f=insert(f);
    }

    disp(f);
    NODE n1=f->link->link;
    NODE n2=n1->link->link->link->link->link;
    printf("Display done\n");
    printf("Swapping %d and %d\n",n1->info,n2->info);
     f=swap(f,n1,n2);
   disp(f);
    return 0;
}

NODE insert(NODE pf)
{
    NODE nn;
    nn=(NODE)malloc(sizeof(struct node));
    printf("\nEnter info : ");
    scanf("%d",&nn->info);
    nn->link=NULL;
    nn->link=pf;
    pf=nn;
    return pf;
}

void disp(NODE pf)
{
    if(pf==NULL)
    {
        printf("Empty\n");
    }
    while(pf!=NULL)
    {
        printf("%d\t",pf->info);
        pf=pf->link;
    }
    printf("\n");
}

NODE swap(NODE pf,NODE n1,NODE n2)
{
    NODE pn1=pf;
    NODE pn2=n1->link;

    while(pn1->link!=n1)
    {
        pn1=pn1->link;
    }

     while(pn2->link!=n2)
    {
        pn2=pn2->link;
    }

    pn1->link=n2;
    pn2->link=n1;

    NODE t=n1->link;
    n1->link=n2->link;
    n2->link=t;

    return pf;
}
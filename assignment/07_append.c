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
NODE append(NODE,NODE);

int main(){
    NODE f1=NULL;
    NODE f2=NULL;
    printf("Enter node 1\n");
    for(int i=0;i<5;i++)
    {
        f1=insert(f1);
    }
     printf("Enter node 2\n");
    for(int i=0;i<5;i++)
    {
        f2=insert(f2);
    }

    disp(f1);disp(f2);
    printf("Display done\n");
      f1=append(f1,f2);
  disp(f1);disp(f2);
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

NODE append(NODE pf1,NODE pf2)
{
    NODE tp=pf1;
    while(pf1->link!=NULL)
    {
pf1=pf1->link;
    }
    pf1->link=pf2;
    return tp;
}
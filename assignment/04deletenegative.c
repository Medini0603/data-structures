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
NODE deleteneg(NODE);

int main(){
    NODE f=NULL;
    for(int i=0;i<5;i++)
    {
        f=insert(f);
    }

    disp(f);
    printf("Display done\n");
     f=deleteneg(f);
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

NODE deleteneg(NODE pf)
{
    NODE nd=pf;
    while(nd->info<0)
    {
        printf("%d is negative hence deleted\n",nd->info);
        pf=nd->link;
        free(nd);
        nd=pf;
    }
nd=pf;
NODE pn=NULL;
    while(nd!=NULL)
    {
        if(nd->info<0)
        {
            printf("%d is negative hence deleted\n",nd->info);
           pn->link=nd->link;
           free(nd);
           nd=pn->link;
            
        }
        else{
            pn=nd;
            nd=nd->link;
        }
    }
   
     return pf;
}
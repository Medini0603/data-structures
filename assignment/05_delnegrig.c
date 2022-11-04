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
NODE delnegrig(NODE);

int main(){
    NODE f=NULL;
    for(int i=0;i<5;i++)
    {
        f=insert(f);
    }

    disp(f);
    printf("Display done\n");
     f=delnegrig(f);
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

NODE delnegrig(NODE pf)
{
    NODE nd=pf;
    NODE tn=pf;
    while(pf->link !=NULL)
    {
        if(pf->info<0)
        {
            nd=pf->link;
            pf->link=nd->link;
            printf("%d is deleted\n",nd->info);
            free(nd);
            pf=pf->link;
            if(pf==NULL){break;}
        }
        else{
            pf=pf->link;
        }
    }
    return tn;
}
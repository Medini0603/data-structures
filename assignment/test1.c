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
NODE searchinsert(NODE,int);

int main(){
    NODE f=NULL;
    for(int i=0;i<5;i++)
    {
        f=insert(f);
    }

    disp(f);
    printf("Display done\n");
    printf("Enter key to be searched\n");
    int x;
    scanf("%d",&x);
    f=searchinsert(f,x);
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

NODE searchinsert(NODE pf,int x)
{
    int flag=0,pos=1;
    NODE tn=pf;
    NODE pp=NULL;
    while(pf!=NULL)
    {
        if(pf->info==x)
        {
            flag=1;
            printf("%d found at %d\n",x,pos);
            break;
        }
        pos++;
        pp=pf;
        pf=pf->link;
    }
    if(flag==0)
    {
        NODE nn;
        nn=(NODE)malloc(sizeof(struct node));
        nn->info=x;
        nn->link=NULL;
        pp->link=nn;
    }
    return tn;
}
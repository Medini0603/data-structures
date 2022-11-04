#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE createnode()
{
    NODE nn = (NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    scanf("%d", &nn->info);
    nn->rlink = nn->llink = NULL;
    return nn;
}

void insertfront(NODE h)
{
    NODE nn = createnode();
    nn->llink = h;
    nn->rlink = h->rlink;
    if(h->rlink!=NULL)h->rlink->llink=nn;
    h->rlink = nn;
    //if(h->rlink!=NULL)h->rlink->llink=nn;
    //----->if we do it here then already h->rlink=nn
    // and thus instead of updating initial first nodes link to nn
    //nn->llink points to nn only  SAD:-(
    h->info++;
}

void disp(NODE h)
{
    if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }
    NODE fp = h->rlink;
    while (fp != NULL)
    {
        printf("%d\t", fp->info);
        fp = fp->rlink;
    }

    printf("\n");
}

void disprev(NODE h)
{
     if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }
    NODE t=h->rlink;
    while(t->rlink!=NULL)
        t=t->rlink;
    while(t!=h)
    {
        printf("%d\t",t->info);
        t=t->llink;
    }
    printf("\n");
}

void insertrear(NODE h)
{
    NODE nn=createnode();
    NODE tp=h;
    while(tp->rlink!=NULL)
        tp=tp->rlink;
    nn->llink=tp;
    nn->rlink=NULL;
    tp->rlink=nn;
    h->info++;
    //return h;
}

void deletefront(NODE h)
{
    if(h->info==0)
    {
        printf("No items to delete\n");
        return ;
    }

    NODE nd=h->rlink;
    printf("%d deleted\n",nd->info);
    // if(h->rlink!=NULL)h->rlink->llink=h;
    // h->rlink=nd->rlink;
    if(nd->rlink!=NULL)nd->rlink->llink=h;
    h->rlink=nd->rlink;
    free(nd);
    h->info--;
}

void deleterear(NODE h)
{
     if(h->info==0)
    {
        printf("No items to delete\n");
        return ;
    }

    NODE tp=h;
    while(tp->rlink!=NULL)
        tp=tp->rlink;
    tp->llink->rlink=NULL;
    printf("Deleted %d\n",tp->info);
    h->info--;
    free(tp);
    // return h;
}

NODE search(NODE h)
{
     if(h->info==0)
    {
        printf("No items to search\n");
        return NULL;
    }

    printf("Enter key\n");
    int key;
    scanf("%d",&key);
    NODE tp=h->rlink;
    while(tp!=NULL && key!=tp->info)
            tp=tp->rlink;
    if(tp==NULL)return NULL;
    return tp;
}

void sort(NODE h)
{
    NODE tp=h->rlink;
    for(int i=0;i<h->info-1;i++)
    {
        for(int j=0;j<h->info-i-1;j++)
        {
            if(tp->info>tp->rlink->info)
            {
                int temp=tp->info;
                tp->info=tp->rlink->info;
                tp->rlink->info=temp;
            }
            tp=tp->rlink;
        }
        tp=h->rlink;
    }

    printf("Sorted array\n");
    disp(h);
    //return h;
}

void deletebykey(NODE h)
{
     if(h->info==0)
    {
        printf("No items to delete\n");
        return ;
    }

    printf("Enter info of node to be deleted\n");
    int key;
    scanf("%d",&key);
    NODE tp=h->rlink;
    while(tp!=NULL && tp->info!=key)
        tp=tp->rlink;
    if(tp==NULL)
    {
        printf("Element not found no deletion\n");
        return ;
    }

    tp->llink->rlink=tp->rlink;
  //  printf("%d link updated\n",tp->llink->info);
    if(tp->rlink!=NULL)tp->rlink->llink=tp->llink; //  printf("%d link updated\n",tp->rlink->info);}
    printf("%d deleted\n",tp->info);
    h->info--;
    free(tp);
   // return h;
}

void insertbypos(NODE h)
{
    printf("Enter position\n");
    int pos;
    scanf("%d",&pos);
    NODE nn=createnode();
    int cnt=0;
    NODE tp=h;
    NODE temp;
    while(tp!=NULL && cnt!=pos)
    {
        if(tp->rlink==NULL){temp=tp;}
        tp=tp->rlink;
        cnt=cnt+1;
    }
    if(cnt!=pos)
    {
        printf("Invalid poition\n");
        return;
    }
    //seperate case for last insertion because last insertion needs traversal again 
    //as previous node link will not be present
    if(tp==NULL)
    {
        nn->llink=temp;
        temp->rlink=nn;
    }
    else{
    nn->llink=tp->llink;
    nn->rlink=tp;
    tp->llink->rlink=nn;
    tp->llink=nn;
  }
    h->info++;
}

void deletebypos(NODE h)
{
     if(h->info==0)
    {
        printf("No items to delete\n");
        return ;
    }

    printf("Enter position\n");
    int pos;
    scanf("%d",&pos);

    int cnt=0;
    NODE tp=h;
    while(tp->rlink!=NULL&&cnt!=pos)
    {
        tp=tp->rlink;
        cnt++;
    }

    if(cnt!=pos)
    {
        printf("Invalid position\n");
        return;
    }

    printf("%d deleted\n",tp->info);
    tp->llink->rlink=tp->rlink;
    if(tp->rlink!=NULL) tp->rlink->llink=tp->llink;
    h->info--;
    free(tp);
}

void insertbyorder(NODE h)
{
    NODE nn=createnode();
      h->info++;
    if(h->rlink==NULL)
    {
        h->rlink=nn;
        nn->llink=h;
        return;
    }
    NODE tp=h->rlink;
    NODE temp;
    while(tp!=NULL && nn->info>tp->info)
    {
        if(tp->rlink==NULL)temp=tp;
        tp=tp->rlink;
    }

    if(tp==NULL)
    {
        nn->llink=temp;
        temp->rlink=nn;
        return;
    }
    nn->llink=tp->llink;
    nn->rlink=tp;
    tp->llink->rlink=nn;
    tp->llink=nn;
}

void reverse(NODE h)
{
    NODE fp=h->rlink;
    NODE lp=h->rlink;
    while(lp->rlink!=NULL)
        lp=lp->rlink;
    for(int i=1;i<=(h->info)/2;i++)
    {
        int temp=fp->info;
        fp->info=lp->info;
        lp->info=temp;
        fp=fp->rlink;
        lp=lp->llink;
    }
}

NODE copy(NODE h)
{
    NODE c = (NODE)malloc(sizeof(struct node));
    c->info = 0;
    c->rlink = c->llink = NULL;
    NODE tp=h->rlink;
    while(tp!=NULL)
    {
        NODE nn=(NODE)malloc(sizeof(struct node));
        nn->llink=nn->rlink=NULL;
        nn->info=tp->info;
        NODE temp=c;
        while(temp->rlink!=NULL)
            temp=temp->rlink;
        nn->llink=tp;
        tp->rlink=nn;
        c->info++;
        tp=tp->rlink;
    }
    return c;
}
int main()
{
    NODE h = (NODE)malloc(sizeof(struct node));
    h->info = 0;
    h->rlink = h->llink = NULL;

    NODE ns=NULL;NODE c=NULL;
    int choice;
    for(;;)
    {
        printf("\nEnter choice\n1->insertfront\n2->disp\n3->insertrear\n4->deletefront\n5->deleterear\n6->search\n7->sort\n8->deletebykey\n9->disprevse\n10->insertbypos\n11->deletebypos\n12->insertbyorder\n13->reverse\n14->copy\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insertfront(h);disp(h);break;
            case 2:disp(h);break;
            case 3:insertrear(h);disp(h);break;
            case 4:deletefront(h);disp(h);break;
            case 5:deleterear(h);disp(h);break;
            case 6:ns=search(h);
            if(ns==NULL)printf("Node not found\n");
            else printf("Node with info %d is available\n",ns->info);
            break;
            case 7:sort(h);break;
            case 8:deletebykey(h);disp(h);break;
            case 9:disprev(h);disp(h);break;
            case 10:insertbypos(h);disp(h);break;
            case 11:deletebypos(h);disp(h);break;
            case 12:insertbyorder(h);disp(h);break;
            case 13:disp(h);reverse(h);disp(h);break;
            case 14:c=copy(h);disp(c);break;
            default:exit(1);break;
        }
    }
    return 0;
}
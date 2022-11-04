#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE createnode()
{
    NODE nn=(NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    scanf("%d",&nn->info);
    nn->link=NULL;
    return nn;
}

NODE insertfront(NODE f)
{
    NODE nn=createnode();
    if(f==NULL)
    {
        f=nn;
        return f;
    }
    nn->link=f;
    f=nn;
    return f;
}

void disp(NODE f)
{
    if(f==NULL)
    {
        printf("Empty\n");
        return;
    }
    
    while(f!=NULL)
    {
        printf("%d  ",f->info);
        f=f->link;
    }
    printf("\n");
}

NODE insertrear(NODE f)
{
    NODE nn=createnode();
    if(f==NULL)
    {
        f=nn;
        return f;
    }
    
    NODE lp=f;
    while(lp->link!=NULL)
        lp=lp->link;
    lp->link=nn;
    return f;
}

NODE deletefront(NODE f)
{
    if(f==NULL)
    {
          printf("List empty nothing to delete\n");
          return NULL;
    }
    NODE nd=f;
    f=nd->link;
    printf("%d deleted\n",nd->info);
    free(nd);
    return f;
}

NODE deleterear(NODE f)
{
    if(f==NULL)
    {
          printf("List empty nothing to delete\n");
          return NULL;
    }
    NODE nd=f;
    NODE pp=NULL;
    while(nd->link!=NULL)
    {
        pp=nd;
        nd=nd->link;
    }
    
    if(pp==NULL)
        f=NULL;
    else pp->link=nd->link;
    printf("%d deleted\n",nd->info);
    free(nd);
    return f;
}

NODE search(NODE f)
{
    if(f==NULL)
    {
          printf("List empty nothing to search\n");
          return NULL;
    }
    int key;
    printf("Enter key\n");
    scanf("%d",&key);
    int pos=1;
    while(f!=NULL)
    {
        if(f->info==key)
        {
            printf("NODE found at %d\n",pos);
            return f;
        }
        f=f->link;
        pos++;
    }
    return NULL;
}

NODE sort(NODE f)
{
    int i,j;
    int n=0;
    NODE fp=f;
    while(fp!=NULL)
        {n++;fp=fp->link;}
        fp=f;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(fp->info>fp->link->info)
            {
                int temp=fp->info;
                fp->info=fp->link->info;
                fp->link->info=temp;
            }
            fp=fp->link;
        }
        fp=f;
    }
    return f;
}

NODE insertbyorder(NODE f)
{
    NODE nn=createnode();
    if(f==NULL)
    {f=nn;return f;}
    NODE tp=f,pp=NULL;
    while(tp!=NULL&&nn->info>tp->info)
    {
        pp=tp;
        tp=tp->link;
    }
    
    if(pp==NULL){nn->link=f;f=nn;return f;}
    pp->link=nn;
    nn->link=tp;
    return f;
}

NODE deletebyelem(NODE f)
{
    if(f==NULL)
    {
          printf("List empty nothing to delete\n");
          return NULL;
    }
    NODE nd=f,pp=NULL;
    int key;
    printf("Enter key\n");
    scanf("%d",&key);
    while(nd!=NULL &&nd->info!=key)
    {
        pp=nd;
        nd=nd->link;
    }
    if(nd==NULL){printf("Not found\nNO deletion\n");return f;}
    if(pp==NULL){f=nd->link;}
    else pp->link=nd->link;
    printf("Deleted %d\n",nd->info);
    free(nd);
    return f;
}

NODE insertbypos(NODE f)
{
    int pos;
    printf("Enter position\n");
    scanf("%d",&pos);
    NODE nn=createnode();
    int cnt=1;
    NODE tp=f,pp=NULL;
    while(tp!=NULL&&cnt!=pos)
    {
        pp=tp;
        tp=tp->link;
        cnt++;
    }
    if(cnt!=pos){printf("Invalid position\n");return f;}
    if(f==NULL){f=nn;return f;}
    if(pp==NULL){nn->link=f;f=nn;return f;}
    if(tp==NULL){pp->link=nn;}
    else {pp->link=nn;nn->link=tp;}
    return f;
}

NODE deletebypos(NODE f)
{
    if(f==NULL)
    {
          printf("List empty nothing to delete\n");
          return NULL;
    }
    int pos;
    printf("Enter position\n");
    scanf("%d",&pos);
    int cnt=1;
    NODE nd=f,pp=NULL;
    while(nd->link!=NULL&&cnt!=pos)
    {
        pp=nd;
        nd=nd->link;
        cnt++;
    }
    if(cnt!=pos){printf("Invalid position\n");return f;}
    if(pp==NULL){f=nd->link;}
    else pp->link=nd->link;
    printf("Deleted %d\n",nd->info);
    free(nd);
    return f;
}

NODE reverse(NODE fp)
{
    NODE tp=NULL,lp=NULL;
    while(fp!=NULL)
    {
        lp=fp;
        fp=fp->link;
        lp->link=tp;
        tp=lp;
    }
    return lp;
}
void main()
{
    NODE f=NULL;
    NODE ns;
    int choice;
    for(;;)
    {
        printf("\nEnter choice\n1->insertfront\n2->display\n3->insertrear\n4->deletefront\n5->deleterear\n6->search\n7->sort\n8->insertbyorder\n9->deletebyelem\n10->insertbypos\n11->deletebypos\n12->reverse\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:f=insertfront(f);disp(f);break;
            case 2:disp(f);break;
            case 3:f=insertrear(f);disp(f);break;
            case 4:f=deletefront(f);disp(f);break;
            case 5:f=deleterear(f);disp(f);break;
            case 6:ns=search(f);
                    if(ns==NULL)printf("NODE not available\n");
                    else printf("NODE available\n");
                    break;
            case 7:f=sort(f);disp(f);break;
            case 8:f=insertbyorder(f);disp(f);break;
            case 9:f=deletebyelem(f);disp(f);break;
            case 10:f=insertbypos(f);disp(f);break;
            case 11:f=deletebypos(f);disp(f);break;
            case 12:f=reverse(f);disp(f);break;
            default:exit(0);break;
        }
    }
}
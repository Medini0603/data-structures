#include<stdio.h>
#include<stdlib.h>

typedef struct node
		{
		int info;
		struct node *link;
		}*NODE;

NODE createNODE()
{
NODE n;
n=(NODE)malloc(sizeof(struct node));
printf("\nEnter the new NODE info:\n");
scanf("%d",&n->info);
n->link=NULL;
return n;
}
	
NODE insertfront(NODE f)
{
NODE nn=createNODE();
nn->link=f;
f=nn;
return f;
}

void display(NODE f)
{
NODE tn=f;
if(f==NULL)
	{
	printf("\nEmpty list!\n");
	return;
	}
while(tn!=NULL)
	{
	printf("%d   ",tn->info);
	tn=tn->link;
	}
}

NODE insertrear(NODE f)
{
NODE nn=createNODE();
NODE tn;
if(f==NULL)
	{
	f=nn;
	return f;
	}
tn=f;
while(tn->link!=NULL)
	tn=tn->link;
tn->link=nn;
return f;
}

NODE deletefront(NODE f)
{
if(f==NULL)
	{
	printf("\nCannot delete from an empty list!\n");
	return NULL;
	}
NODE nd=f;
f=f->link;
printf("\nDeleted %d\n",nd->info);
free(nd);
return f;
}

NODE deleterear(NODE f)
{
if(f==NULL)
	{
	printf("\nCannot delete from an empty list!\n");
	return NULL;
	}
NODE pn,nd;
pn=NULL;
nd=f;
while(nd->link!=NULL)
	{
	pn=nd;
	nd=nd->link;
	}
if(pn==NULL);
	{
	printf("\nDeleted %d\n",nd->info);
	free(nd);
	return NULL;
	}
pn->link=NULL;
printf("\nDeleted %d\n",nd->info);
free(nd);
return f;
}

void main()
{
NODE s=NULL;
int ch;
while(1)
	{
	printf("\nEnter your choice:\n1->insert front\n2->display\n3->insert rear\n4->delete front\n5->delete rear\n");
	scanf("%d",&ch);
	switch(ch)
		{
		case 1:s=insertfront(s);display(s);break;
		case 2:display(s);break;
		case 3:s=insertrear(s);display(s);break;
		case 4:s=deletefront(s);display(s);break;
		case 5:s=deleterear(s);display(s);break;
		default:exit(0);break;
		}
	}
}
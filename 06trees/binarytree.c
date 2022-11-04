#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int info;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
NODE createnode()
{
    NODE nn = (NODE)malloc(sizeof(struct node));
    printf("Enter node info\n");
    scanf("%d", &nn->info);
    nn->llink = nn->rlink = NULL;
    return nn;
}

NODE insert(NODE root)
{
    NODE nn = createnode();
    char str[10];
    NODE pn, tp;
    int i;
    if (root == NULL)
        return nn;
    printf("Enter the direction\n");
    scanf("%s", str);
    pn = NULL;
    tp = root;
    for (i = 0; i < strlen(str); i++)
    {
        // pn=NULL;tp=root;
        if (tp == NULL)
            break;
        pn = tp;
        if (str[i] == 'L' || str[i] == 'l')
            tp = tp->llink;
        else
            tp = tp->rlink;
    }

    if (tp != NULL)
    {
        printf("Insertion not possible\n");
        return root;
    }
    if (strlen(str) != i)
    {
        printf("Invalid direction\n");
        return root;
    }

    if (str[i - 1] == 'l' || str[i - 1] == 'L')
        pn->llink = nn;
    else
        pn->rlink = nn;
    return root;
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d\t", root->info);
    inorder(root->rlink);
}

void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->info);
}

NODE search(NODE root, int key)
{
    NODE ns = NULL;
    if (root == NULL)
        return root;
    if (root->info == key)
        return root; // or//ns=root;
   if (ns == NULL)
        ns = search(root->llink, key);
   if (ns == NULL)
        ns = search(root->rlink, key);
    return ns;
}

NODE copy(NODE root)
{
    if (root == NULL)
        return NULL;
    NODE nn = NULL;
    nn = (NODE)malloc(sizeof(struct node));
    nn->llink = nn->rlink = NULL;
    nn->info = root->info;
    nn->llink = copy(root->llink);
    nn->rlink = copy(root->rlink);
    return nn;
}

int height(NODE root)
{
    if (root == NULL)
        return -1;
    return 1 + max(height(root->rlink), height(root->llink));
}

NODE searchdel(NODE root,int key,NODE *pn)
{
     NODE ns = NULL;
    // *pn=NULL;
    if (root == NULL)
        return root;
    if (root->info == key)
        return root; /*ns=root;*/
    if (ns == NULL)
    {
        *pn=root;
        ns = searchdel(root->llink, key,pn);
    }
    if (ns == NULL)
    {
        *pn=root;
        ns = searchdel(root->rlink, key,pn);
    }
    return ns;
}

NODE delete(NODE root)
{
    int key;
    printf("Enter key to be deleted\n");
    scanf("%d",&key);
    NODE pn=NULL;
   
    NODE nd;
    //if key is a root dont search directly assign
     if(key==root->info)
     {
         nd=root;
         pn=NULL;
     }
    else 
    {
        nd=searchdel(root,key,&pn);
        printf("Parent node info %d\n",pn->info);
    }
    if(nd==NULL)
    {
        printf("Key not found\n");
        return root;
    }

    printf("%d deleted\n",nd->info);
    //case 1:
    if(nd->llink==NULL &&nd->rlink==NULL)
    {
        if(pn==NULL)return NULL;//root deletion with no child
        if(nd==pn->llink)pn->llink=NULL;
        else pn->rlink=NULL;
        free(nd);
        return root;
    }

    //case 2:
    if((nd->llink==NULL&&nd->rlink!=NULL) ||(nd->rlink==NULL && nd->llink!=NULL))
    {
        
      
        if(nd->rlink!=NULL)
        {
            if(pn==NULL){ root= nd->rlink;free(nd);return root;}//root with one child (right child)
            if(nd==pn->llink)pn->llink=nd->rlink;
            else pn->rlink=nd->llink;
            free(nd);
        }

        else
        {
            if(pn==NULL){root= nd->llink;free(nd);return root;}//root with one child (left child)
            if(nd==pn->llink) pn->llink=nd->llink;
            else pn->rlink=nd->llink;
            free(nd);
        }
        return root;
    }

    //case 3:
    if(nd->rlink!=NULL &nd->llink!=NULL)
    {
        NODE is=nd->rlink;
        NODE pis=nd;
        NODE temp=is->llink;

        while(temp!=NULL)
        {
            pis=is;
            is=is->llink;
            temp=temp->llink;
        }

        nd->info=is->info;
        if(is->rlink==NULL/*is->llink==NULL*/)
        {
            if(is==pis->llink)pis->llink=NULL;
            else pis->rlink=NULL;
        }

        else
        {
            if(is==pis->rlink)pis->rlink=is->rlink;
            else pis->llink=is->rlink;
        }
        free(is);
        return root;
    }

}
int main()
{
    NODE root = NULL;
    int choice, key;
    NODE ns;
    NODE cp = NULL;
    int d;
    for (;;)
    {
        printf("\nEnter choice\n1->insert\n2->display\n3->search\n4->copy\n5->depth\n6->deletebykey\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = insert(root);
            // disp(root);
            break;
        case 2:
            printf("Inoder\n");
            inorder(root);
            printf("\n");
            printf("preoder\n");
            preorder(root);
            printf("\n");
            printf("postorder\n");
            postorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter key\n");
            scanf("%d", &key);
            ns = search(root, key);
            if (ns == NULL)
                printf("Node not found\n");
            else
                printf("%d found\n", key);
            break;

        case 4:
            cp = copy(root);
            printf("Inorder of copied tree\n");
            inorder(cp);
            break;
        case 5:
            d = height(root);
            printf("Height of tree : %d\n", d);
            break;
        case 6:
            root=delete(root);
            inorder(root);
            break;
        }
    }
    return 0;
}
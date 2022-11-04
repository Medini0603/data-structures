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
    nn->llink = nn->rlink = NULL;
    return nn;
}

NODE create(NODE r)
{
    NODE nn = createnode();
    if (r == NULL)
        return nn;
    NODE cn = r;
    NODE pn = NULL;
    while (cn != NULL)
    {
        pn = cn;
        if (cn->info > nn->info)
            cn = cn->llink;
        else
            cn = cn->rlink;
    }

    if (pn->info < nn->info)
        pn->rlink = nn;
    else
        pn->llink = nn;

    return r;
}

void inorder(NODE r)
{
    if (r == NULL)
        return;
    inorder(r->llink);
    printf("%d\t", r->info);
    inorder(r->rlink);
}

void preorder(NODE r)
{
    if (r == NULL)
        return;
    printf("%d\t", r->info);
    preorder(r->llink);
    preorder(r->rlink);
}

void postorder(NODE r)
{
    if (r == NULL)
        return;
    postorder(r->llink);
    postorder(r->rlink);
    printf("%d\t", r->info);
}
int cnt = 0;
NODE search(NODE root, int key)
{
    cnt++;
    NODE ns = NULL;
    if (root == NULL)
        return root;
    if (key == root->info)
        return root;
    if (key > root->info)
        ns = search(root->rlink, key);
    if (key < root->info)
        ns = search(root->llink, key);
    return ns;
}

NODE maximum(NODE r)
{
    NODE max = r;
    while (max->rlink != NULL)
        max = max->rlink;
    return max;
}

NODE minimum(NODE r)
{
    NODE min = r;
    while (min->llink != NULL)
        min = min->llink;
    return min;
}

void count(NODE r, int *n)
{
    if (r == NULL)
        return;
          *n = *n + 1;
    count(r->llink, n);
    count(r->rlink, n);
}

void countleaf(NODE r, int *n)
{
    if (r == NULL)
        return;
    countleaf(r->llink, n);
    if (r->llink == NULL && r->rlink == NULL)
        *n = *n + 1;
    countleaf(r->rlink, n);
}
int main()
{
    NODE root = NULL;
    int choice, key;
    NODE ns;
    NODE max, min;
    int n = 0;
    int nleaf = 0;
    for (;;)
    {
        printf("\nEnter choice\n1->insert\n2->display\n3->search\n4->maxmin\n5->count\n6->countleaf\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = create(root);
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
            cnt = 0;
            ns = search(root, key);
            printf("Number of iteraations is %d\n", cnt);
            if (ns == NULL)
                printf("Node not found\n");
            else
                printf("%d found\n", key);
            break;
        case 4:
            max = maximum(root);
            printf("Maximum = %d\n", max->info);
            min = minimum(root);
            printf("Mimimum = %d\n", min->info);
            break;

        case 5:
            n = 0;
            count(root, &n);
            printf("Number of nodes = %d\n", n);
            break;

        case 6:
            nleaf = 0;
            countleaf(root, &nleaf);
            printf("Number of leaf nodes = %d\n", nleaf);
            break;
        }
    }
    return 0;
}
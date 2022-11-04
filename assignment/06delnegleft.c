#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insert(NODE);
void disp(NODE);
NODE delnegleft(NODE);

int main()
{
    NODE f = NULL;
    for (int i = 0; i < 5; i++)
    {
        f = insert(f);
    }

    disp(f);
    printf("Display done\n");
    f = delnegleft(f);
    disp(f);
    return 0;
}

NODE insert(NODE pf)
{
    NODE nn;
    nn = (NODE)malloc(sizeof(struct node));
    printf("\nEnter info : ");
    scanf("%d", &nn->info);
    nn->link = NULL;
    nn->link = pf;
    pf = nn;
    return pf;
}

void disp(NODE pf)
{
    if (pf == NULL)
    {
        printf("Empty\n");
    }
    while (pf != NULL)
    {
        printf("%d\t", pf->info);
        pf = pf->link;
    }
    printf("\n");
}

NODE delnegleft(NODE pf)
{
    NODE nd = pf;
    NODE tp = pf;
    NODE pp = NULL;
    while (pf->link != NULL)
    {
        if (pf->link->info < 0)
        {
            nd = pf;
            if (nd == tp)
            {
                tp = nd->link;
                printf("%d deleted\n", nd->info);
                free(nd);
                pf = tp;
            }

            else
            {
                pp->link = nd->link;
                pf = nd->link;
                printf("%d deleted\n", nd->info);
                free(nd);
            }
        }
        pp = pf;
        pf = pf->link;
        if(pf==NULL)break;
    }
    return tp;
}
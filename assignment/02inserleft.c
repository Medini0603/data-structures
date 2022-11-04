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
NODE inserleft(NODE, int);

int main()
{
    NODE f = NULL;
    for (int i = 0; i < 5; i++)
    {
        f = insert(f);
    }

    disp(f);
    printf("Display done\n");
    int pos;
    printf("Enter pos\n");
    scanf("%d", &pos);
    f = inserleft(f, pos);
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

NODE inserleft(NODE pf, int pos)
{
    NODE nn;
    nn = (NODE)malloc(sizeof(struct node));
    printf("\nEnter info : ");
    scanf("%d", &nn->info);
    nn->link = NULL;

    NODE pn, tn;
    tn = pf;
    int count = 1;
    while (count < pos - 1)
    {
        tn = tn->link;
        count++;
    }

    if (tn == pf)
    {
        nn->link = pf;
        pf = nn;
    }
    else
    {
        nn->link = tn->link;
        tn->link = nn;
    }
    return pf;
}
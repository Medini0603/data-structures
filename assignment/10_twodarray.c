#include <stdio.h>
#include <stdlib.h>

struct node1
{
    int info;
    struct node1 *link;
};
typedef struct node1 *NODE1;
struct node2
{
    NODE1 col;
    struct node2 *row;
};
typedef struct node2 * NODE2;
NODE2 insertrear2(NODE2);
NODE1 insertrear1(NODE1);
void disp(NODE1);

int main()
{
    int r, c, i, j;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d", &r, &c);
    printf("Number of rows %d and columns %d\n",r,c);
    NODE2 table;
    table = NULL;

    for (i = 1; i <= r; i++)
    {
        table = insertrear2(table);
    }

   NODE2 f2 =NULL;
     f2= table;
    NODE1 f1=NULL;
    printf("Enter the elements of matrix one by one\n");
 while(f2!=NULL)
    {
          f2->col=f1;

        f1=NULL;
        for (j = 1; j <= c; j++)
        {
            f1 = insertrear1(f1);
        }
        f2 = f2->row;
    }
    printf("Input done\n");
    NODE2 d2 = table;
    NODE1 d1=d2->col;
    printf("the elements of matrix are\n");
  do
    {
        disp(d1);
        printf("\n");
          d2 = d2->row;
          d1=d2->col;
       
    } while(d2!=NULL);
    return 0;
}

NODE2 insertrear2(NODE2 pf)
{
    NODE2 nn = (NODE2)malloc(sizeof(struct node2));
    nn->row = NULL;
    nn->col=NULL;
        NODE2 lp;
    lp=pf;
    if (pf == NULL)
        return nn;
    else
    {
        while (pf->row != NULL)
            pf = pf->row;

        pf->row = nn;
        return lp;
    }
}

NODE1 insertrear1(NODE1 pf)
{
    NODE1 temp = pf;
    NODE1 nn = (NODE1)malloc(sizeof(struct node1));
    printf("Enter info\n");
    scanf("%d", &nn->info);
    nn->link = NULL;
      NODE1 lp=pf;
    if (pf == NULL)
        return nn;
    else
    {
        while (pf->link != NULL)
            pf = pf->link;

        pf->link = nn;
        return lp;
    }
}

void disp(NODE1 pf)
{
    while (pf != NULL)
    {
        printf("%d\t", pf->info);
        pf = pf->link;
    }
}
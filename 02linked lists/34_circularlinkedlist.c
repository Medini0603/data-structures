#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insertfront(NODE);
NODE createnode(NODE);
void disp(NODE);
NODE insertrear(NODE);
NODE deletefront(NODE);
NODE deleterear(NODE);
NODE search(NODE);
void sort(NODE);
NODE insertbyorder(NODE);
NODE deletebyelem(NODE);
NODE reverse(NODE);
NODE insertbypos(NODE);
NODE deletebypos(NODE);
NODE copy(NODE);

int count = 0;

int main()
{
    int choice;
    NODE l = NULL;
    NODE ns = NULL;
    NODE c=NULL;
    for (;;)
    {
        printf("\nEnter your choice\n1->insertfront\n2->display\n3->insertrear\n4->deletefront\n5->deleterear\n6->search\n7->sort\n8->insertbyorder\n9->deletebyelement\n10->reverse\n11->insertbypos\n12->deletebypos\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            l = insertfront(l);
            disp(l);
            break;

        case 2:
            disp(l);
            break;

        case 3:
            l = insertrear(l);
            disp(l);
            break;

        case 4:
            l = deletefront(l);
            disp(l);
            break;

        case 5:
            l = deleterear(l);
            disp(l);
            break;

        case 6:
            ns = search(l);
            if (ns == NULL)
                printf("Node not found\n");
            else
                printf("Node is available\n");
            break;

        case 7:
            sort(l);
            disp(l);
            break;

        case 8:
            l = insertbyorder(l);
            disp(l);
            break;

        case 9:
            l = deletebyelem(l);
            disp(l);
            break;

        case 10:
            l = reverse(l);
            disp(l);
            break;

        case 11:
            l = insertbypos(l);
            disp(l);
            break;
        case 12:
            l = deletebypos(l);
            disp(l);
            break;
        case 13:
             c = copy(l);
            printf("Copied\n");
            disp(c);
            printf("\nOriginal\n");
            disp(l);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}

NODE createnode(NODE n)
{
    NODE nn = NULL;
    nn = (NODE)malloc(sizeof(int));
    printf("Enter info\n", nn->info);
    scanf("%d", &nn->info);
    return nn;
}

NODE insertfront(NODE lp)
{
    NODE nn = NULL;
    nn = createnode(nn);
    if (lp == NULL)
        lp = nn;
    else
        nn->link = lp->link;
    lp->link = nn;

    return lp;
}

void disp(NODE lp)
{
    if (lp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE pf = lp->link;
    printf("The elemnts in the list are\n");
    do
    {
        printf("%d\t", pf->info);
        pf = pf->link;
    } while (pf != lp->link);
}

NODE insertrear(NODE lp)
{
    NODE nn = NULL;
    nn = createnode(nn);

    if (lp == NULL)
        lp = nn;
    else
        nn->link = lp->link;
    lp->link = nn;
    return nn;
}

NODE deletefront(NODE lp)
{
    if (lp == NULL)
    {
        printf("LIST empty...no element to be deleted\n");
        return NULL;
    }
    else
    {
        NODE nd = lp->link;
        if (nd == lp)
        {
            printf("%d deleted\n", nd->info);
            free(nd);
            lp = NULL;
        }

        else
        {
            lp->link = nd->link;
            printf("%d deleted\n", nd->info);
            free(nd);
        }
        return lp;
    }
}

// NODE deleterear(NODE lp)
// {
//     if (lp == NULL)
//     {
//         printf("LIST empty...no element to be deleted\n");
//         return NULL;
//     }
//     else
//     {
//         NODE nd = lp->link;
//         if (nd == lp)
//         {
//             printf("%d deleted\n", nd->info);
//             free(nd);
//             return NULL;
//         }

//         else
//         {
//             while (nd->link != lp)
//                 nd = nd->link;

//             nd->link = lp->link;
//             printf("%d deleted\n", lp->info);
//             free(lp);
//             return nd;
//         }
//     }
// }
NODE deleterear(NODE lp)
{
    if (lp == NULL)
    {
        printf("LIST empty...no element to be deleted\n");
        return NULL;
    }
    NODE nd = lp->link;
    NODE pp = NULL;

    while (nd != lp)
    {
        pp = nd;
        nd = nd->link;
    }
    if (nd == lp->link)
        lp = NULL;
    else
        pp->link = lp->link;
    printf("%d deleted\n", nd->info);
    free(nd);
    return pp;
}

NODE search(NODE lp)
{
    int key, pos = 1;
    if (lp == NULL)
    {
        printf("LIST empty\nNOthing to search\n");
        return NULL;
    }
    else
    {
        printf("Enter key to be searched\n");
        scanf("%d", &key);
        NODE pf = lp->link;
        do
        {
            if (pf->info == key)
            {
                printf("%d found at %d\n", key, pos);
                return pf;
                break;
            }
            pf = pf->link;
            pos++;
        } while (pf != lp->link);
    }
    return NULL;
}

void sort(NODE lp)
{
    int i, j, n = 0;
    NODE pf = lp->link;
    do
    {
        n++;
        pf = pf->link;
    } while (pf != lp->link);

    printf("Number of elements in list = %d\n", n);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (pf->info > pf->link->info)
            {
                int temp = pf->info;
                pf->info = pf->link->info;
                pf->link->info = temp;
            }
            pf = pf->link;
        }
        pf = lp->link;
    }
}

NODE insertbyorder(NODE lp)
{
   // sort(lp);
   // NODE nn = NULL;
    NODE pp = NULL;
    NODE tp = NULL;
 NODE   nn = createnode(nn);

    if (lp == NULL)
    {
        lp = nn;
        lp->link = nn;
    }

    else
    {
        tp = lp->link;
        do
        {
            if (nn->info < tp->info)
                break;
            else
            {
                pp = tp;
                tp = tp->link;
            }
        } while (tp != lp->link);

        if (pp == NULL)
        {
            nn->link = lp->link;
            lp->link = nn;
        }
        else if (tp == lp->link)
        {
            nn->link = lp->link;
            lp->link = nn;
            return nn;
        }
        else
        {
            nn->link = pp->link;
            pp->link = nn;
        }
    }
    return lp;
}

// NODE deletebyelem(NODE lp)
// {
//     if (lp == NULL)
//     {
//         printf("List empty....no element to be deleted\n");
//         return NULL;
//     }

//     int key, flag = 0;
//     printf("enter key\n");
//     scanf("%d", &key);

//     NODE fp = lp->link;
//     NODE nd = NULL;
//     NODE pn = NULL;
//     do
//     {
//         if (fp->info == key)
//         {
//             nd = fp;
//             flag = 1;
//             break;
//         }
//         pn = fp;
//         fp = fp->link;
//     } while (fp != lp->link);

//     if (flag == 0)
//     {
//         printf("Not found no deletion\n");
//         return lp;
//     }

//     else
//     {
//         if (nd == lp->link)
//             lp = deletefront(lp);

//         else if (nd == lp)
//             lp = deleterear(lp);
//         else
//         {
//             pn->link = nd->link;
//             printf("%d deleted\n", nd->info);
//             free(nd);
//             return lp;
//         }
//     }
// }

NODE deletebyelem(NODE lp)
{
    if (lp == NULL)
    {
        printf("List empty....no element to be deleted\n");
        return NULL;
    }

    int key, flag = 0;
    printf("enter key\n");
    scanf("%d", &key);

    NODE fp = lp->link;
    NODE nd = NULL;
    NODE pn = NULL;
    do
    {
        if (fp->info == key)
        {
            nd = fp;
            flag = 1;
            break;
        }
        pn = fp;
        fp = fp->link;
    } while (fp != lp->link);

    // if (flag == 0)
    // {
    //     printf("Not found no deletion\n");
    //     return lp;
    // }
    if (nd == NULL)
    {
        printf("Not found no deletion\n");
        return lp;
    }

    else
    {
        if (nd == lp && nd == lp->link)
            lp = NULL;

        else if (nd == lp->link)
            lp->link = nd->link;

        else if (nd == lp)
        {
            pn->link = lp->link;
            lp = pn;
        }

        else
            pn->link = nd->link;
        printf("%d deleted\n", nd->info);
        free(nd);
        return lp;
    }
}

NODE reverse(NODE lp)
{
    NODE fp = lp->link;
    NODE tp = lp;
    NODE t = lp->link;

    do
    {
        lp = fp;
        fp = fp->link;
        lp->link = tp;
        tp = lp;
    } while (fp != t);

    return fp;
}

NODE insertbypos(NODE lp)
{
    int cnt = 1, pos, flag = 0;
    printf("Enter position\n");
    scanf("%d", &pos);
    NODE nn = NULL;
    nn = createnode(nn);
    if (lp == NULL)
    {
        lp = nn;
        lp->link = nn;
        return lp;
    }
    NODE tp = lp->link;
    NODE pp = NULL;
    do
    {
        if (cnt == pos)
        {
            flag = 1;
            break;
        }
        pp = tp;
        tp = tp->link;
        cnt++;
    } while (tp != lp->link);
    if (pos != cnt)
    {
        printf("Invalid position\n");
        return lp;
    }
    if (pp == NULL)
    {
        nn->link = lp->link;
        lp->link = nn;
    }

    else if (tp == lp->link)
    {
        nn->link = lp->link;
        lp->link = nn;
        lp = nn;
    }

    else
    {
        nn->link = pp->link;
        pp->link = nn;
    }

    return lp;
}

NODE deletebypos(NODE lp)
{
    if (lp == NULL)
    {
        printf("List is empty.....Nothing to delete\n");
        return lp;
    }
    printf("Enter position\n");
    int pos, cnt = 1;
    scanf("%d", &pos);
    NODE nd = lp->link;
    NODE pp = NULL;

    do
    {
        if (pos == cnt)
            break;

        pp = nd;
        nd = nd->link;
        cnt++;
    } while (nd != lp->link);
    if (nd == lp->link && pp != NULL)
    {
        printf("Invalid position\n");
        return lp;
    }
    if (pp == NULL && nd == lp)
        lp = NULL;
    else if (pp == NULL)
        lp->link = nd->link;
    else if (nd == lp)
    {
        pp->link = lp->link;
        lp = pp;
    }
    else
        pp->link = nd->link;
    printf("%d is deleted\n", nd->info);
    free(nd);
    return lp;
}

NODE copy(NODE lp)
{
    NODE nn;
    NODE fp=lp->link;
    NODE c=NULL;
    do
    {
        nn=NULL;
      nn=(NODE)malloc(sizeof(struct node));
      nn->info=fp->info;
      if(c==NULL)c=nn;
      else nn->link=c->link;
      c->link=nn;
      c=nn;
      fp=fp->link;
    } while (fp!=lp->link);
    
    return c;
}
#include <stdio.h>
#include <stdlib.h>
int count = 0;
typedef struct student
{
    int rollno;
    char name[20];
    float marks;
} std;

struct node
{
    std info;
    struct node *link;
};

typedef struct node *NODE;

// NODE insertfront(NODE);
void c();
void readstu(std *);
void insertfront(NODE *);
void display(NODE);
NODE insertrear(NODE);
void deletefront(NODE *);
void deleterear(NODE *);
NODE search(NODE);
void sort(NODE);
NODE insertbyorder(NODE);
NODE deletebyelement(NODE);
NODE reverse(NODE);
void reverseprint(NODE);
NODE insertbypos(NODE);
NODE deletebypos(NODE);
NODE copy(NODE);
void disp(std);
void read(std *);
int main()
{
    NODE SN, cpy;
    int choice;
    NODE f = NULL;
    for (;;)
    {
        printf("\nEnter choice\n1->insert from front\n2->display\n3->insert from rear\n4->delete from front\n5->delete from rear\n6->search\n7->sort\n8->insert by order\n9->delete by key\n10->reverse list\n11->reverese print\n12->insert by position\n13->delete by position\n14->copy\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertfront(&f);
            c();
            display(f);
            break;
        case 2:
            c();
            display(f);
            break;
        case 3:
            f = insertrear(f);
            c();
            display(f);
            break;
        case 4:
            deletefront(&f);
            c();
            display(f);
            break;
        case 5:
            deleterear(&f);
            c();
            display(f);
            break;
        case 6:
            SN = search(f);
            if (SN == NULL)
            {
                printf("Node not found");
            }
            else
            {
                printf("Node found with the info \n");
                disp(SN->info);
            }
            break;

        case 7:
            sort(f);
            display(f);
            break;
        case 8:
            f = insertbyorder(f);
            display(f);
            break;
        case 9:
            f = deletebyelement(f);
            c();
            display(f);
            break;
        case 10:
            f = reverse(f);
            c();
            display(f);
            break;

        case 12:
            f = insertbypos(f);
            c();
            display(f);
            break;

        case 13:
            f = deletebypos(f);
            c();
            display(f);
            break;

        case 14:
            cpy = copy(f);
            printf("\ncopied\n");
            display(cpy);
            printf("\nOriginal\n");
            display(f);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}

void c()
{
    printf("The number of elements in list currntly %d\n", count);
}
void readstu(std *s)
{
    printf("Enter student details\n");
    printf("\nRollno : ");
    scanf("%d", &s->rollno);
    printf("\nName : ");
    scanf("%s", s->name);
    printf("\nPercentage : ");
    scanf("%f", &s->marks);
    printf("\n");
}

void disp(std s)
{
    printf("%d\t\t", s.rollno);
    printf("%s\t\t", s.name);
    printf("%f\t\t", s.marks);
    printf("\n");
}
void insertfront(NODE *fp)
{
    NODE nn;
    nn = (NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    readstu(&nn->info);
    nn->link = *fp;
    *fp = nn;
    count++;
}

void display(NODE fp)
{

    if (fp == NULL)
        printf("The collection is empty\n");
    else
    {
        printf("\nThe collection of students you entered is\n");
        printf("Rollno\t\tName\t\tPercentage\t\t");
        // printf("\n---------------------------------------------------------------------\n");
        while (fp != NULL)
        {
            printf("\n---------------------------------------------------------------------\n");
            disp(fp->info);
            // printf("\n---------------------------------------------------------------------\n");
            fp = fp->link;
        }
    }
}

NODE insertrear(NODE fp)
{
    NODE nn, lp;
    nn = (NODE)malloc(1 * sizeof(struct node));
    printf("Enter info\n");
    readstu(&nn->info);
    nn->link = NULL;
    count++;
    if (fp == NULL)
        return nn;
    lp = fp;
    while (lp->link != NULL)
    {
        lp = lp->link;
    }
    lp->link = nn;
    return fp;
}

void deletefront(NODE *fp)
{
    if (*fp == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    NODE nd;
    nd = *fp;
    *fp = nd->link;
    printf("Deleted student info\n");
    disp(nd->info);
    free(nd);
    count--;
}

void deleterear(NODE *fp)
{
    NODE lp, pp;
    if (*fp == NULL)
    {
        printf("Array is empty\n");
        return;
    }
    count--;
    lp = *fp;
    pp = NULL;
    while (lp->link != NULL)
    {
        pp = lp;
        lp = lp->link;
    }

    if (pp == NULL)
        *fp = NULL;
    else
        pp->link = NULL;
    printf("Deleted info\n");
    disp(lp->info);
    free(lp);
}

NODE search(NODE fp)
{
    if (fp == NULL)
    {
        printf("No elements in the list\n");
        return NULL;
    }

    int key;
    printf("Enter the rollno to be searched\n");
    scanf("%d", &key);

    int pos = 0;
    while (fp != NULL)
    {
        if (key == (fp->info).rollno)
        {
            printf("Node found at position %d\n", pos + 1);
            return fp;
            // break;
        }
        pos++;
        fp = fp->link;
    }

    return NULL;
}

void sort(NODE fp)
{
    int temp, N;
    NODE tp;
    tp = fp;
    // if we have not kept track of count
    while (fp != NULL)
    {
        N++;
        fp = fp->link;
    }
    fp = tp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if ((fp->info).rollno > (fp->link->info).rollno)
            {
                std *p1 = &(fp->info);
                std *p2 = &(fp->link->info);
                std temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
            fp = fp->link;
        }
        fp = tp;
    }
}

NODE insertbyorder(NODE fp)
{
    NODE NN, pp, lp;
    NN = (NODE)malloc(sizeof(struct node));
    printf("Enter the info of the new node\n");
    readstu(&NN->info);
    NN->link = NULL;

    count++;
    pp = NULL;
    lp = fp;
    while (lp != NULL && lp->info.rollno < NN->info.rollno)
    {
        pp = lp;
        lp = lp->link;
    }

    if (pp == NULL)
    {
        NN->link = lp;
        return NN;
    }

    pp->link = NN;
    NN->link = lp;
    return fp;
}

NODE deletebyelement(NODE pf)
{
    int key;
    if (pf == NULL)
    {
        printf("Array is empty\n");
        return NULL;
    }
    printf("Enter the key info to be deleted\n");
    scanf("%d", &key);
    NODE nd, pp;
    nd = pf;
    pp = NULL;
    while (nd != NULL && nd->info.rollno != key)
    {
        pp = nd;
        nd = nd->link;
    }

    if (nd == NULL)
    {
        printf("not found\n");
        return pf;
    }

    if (pp == NULL)
        pf = pf->link;

    else
    {
        pp->link = nd->link;
    }
    printf("%d is deleted\n", nd->info);
    free(nd);
    count--;
    return pf;
}

NODE reverse(NODE fp)
{
    NODE lp, tp;
    lp = NULL;
    tp = NULL;

    while (fp != NULL)
    {
        lp = fp;
        fp = fp->link;
        lp->link = tp;
        tp = lp;
    }
    return lp;
}

NODE insertbypos(NODE fp)
{
    int pos;
    // do
    // {
    //     printf("Enter a valid position between 1 to %d\n", count );
    //     scanf("%d", &pos);
    // } while ((pos < 0)|| (pos > count));
    printf("Enter a valid position between 1 to %d\n", count + 1);
    scanf("%d", &pos);

    NODE nn;
    nn = (NODE)malloc(sizeof(struct node));
    printf("Enter the node info\n");
    readstu(&nn->info);
    nn->link = NULL;
    NODE tp;
    tp = fp;
    if (fp == NULL)
        fp = nn;

    else if (pos == 1)
    {
        nn->link = tp;
        fp = nn;
    }

    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            tp = tp->link;
        }
        nn->link = tp->link;
        tp->link = nn;
    }
    count++;
    return fp;
}

NODE deletebypos(NODE pf)
{
    if (pf == NULL)
    {
        printf("Array is empty\n");
        return NULL;
    }

    int pos, i = 1;
    printf("Enter valid position between 1 to %d\n", count);
    scanf("%d", &pos);

    NODE pn, nd;
    pn = NULL;
    nd = pf;
    if (pos == 1)
    {
        pf = nd->link;
        free(nd);
    }
    else
    {
        while (i <= pos - 1)
        {
            pn = nd;
            nd = nd->link;
            i++;
        }
        pn->link = nd->link;
        free(nd);
    }
    count--;
    return pf;
}

NODE copy(NODE fp)
{
    NODE cp = NULL;
    NODE p;
    while (fp != NULL)
    {

        NODE nn = NULL;
        nn = (NODE)malloc(sizeof(struct node));
        std *o;
        o = &fp->info;
        std *c;
        c = &nn->info;
        *c=*o;
        nn->link = NULL;
        if (cp == NULL)
            cp = nn;
        else
            p->link = nn;
        p = nn;
        fp = fp->link;
    }
    return cp;
}
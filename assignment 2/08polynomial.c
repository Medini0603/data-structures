//  Design a menu driven program to perform the following 
//with linked list storage structures 
// i) Create (Read)a polynomial 
// ii) Display a polynomial 
// iii) Evaluate a polynomial 
// iv) Add two polynomials  


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct poly
{
    int coeff;
    int px;
    struct poly *link;
};

typedef struct poly *POLY;
POLY read(POLY);
POLY createnode(POLY);
POLY insertrear(POLY, POLY);
void disp(POLY);
int evaluate(POLY);
int cnt(POLY);
POLY add(POLY, POLY);

void main()
{
    POLY l = NULL;
    int choice;
    int result;
    POLY sum;
    POLY l2 = NULL;
    for (;;)
    {
        printf("\nEnter your choice\n1->read\n2->display\n3->evaluate\n4->addition\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            l = read(l);
            break;
        case 2:
            disp(l);
            break;
        case 3:
            result = evaluate(l);
            printf("The evaluated value is %d\n", result);
            break;
        case 4:
            printf("Enter the other polynomial to be added\n");
            l2 = read(l2);
            sum = add(l, l2);
            printf("The adittion of 2 polynomials is \n");
            disp(sum);
            break;
        default:
            exit(0);
            break;
        }
    }
}

POLY read(POLY l)
{
    int digit;
    int pow;
    for (;;)
    {
        printf("Enter the polynomial in descending powers of x\n");
        printf("\nEnter your coefficient\n");
        printf("\nEnter the coefficient of next term as -999 to terminate\n");
        scanf("%d", &digit);
        if (digit == -999)
            break;
        printf("Enter power of this coefficient\n");
        scanf("%d", &pow);
        POLY nn = createnode(nn);
        nn->coeff = digit;
        nn->px = pow;
        l = insertrear(l, nn);
    }
    return l;
}

POLY createnode(POLY n)
{
    POLY nn = (POLY)malloc(sizeof(struct poly));
    nn->link = NULL;
    return nn;
}

POLY insertrear(POLY lp, POLY n)
{
    if (lp == NULL)
        lp = n;
    else
        n->link = lp->link;
    lp->link = n;
    return n;
}
int cnt(POLY l)
{
    POLY tp = l->link;
    int n = 0;
    do
    {
        n++;
        tp = tp->link;
    } while (tp != l->link);
    return n;
}
void disp(POLY l)
{
    POLY tp = l->link;
    do
    {
        if (tp->coeff >= 0)
            printf("+");
        if (tp->px == 0)
            printf(" %d ", tp->coeff);
        else
            printf(" %dx^%d ", tp->coeff, tp->px);
        tp = tp->link;
    } while (tp != l->link);
    printf("\nNumber of elements %d\n", cnt(l));
}

int evaluate(POLY l)
{
    int n;
    printf("Enter the value of x\n");
    scanf("%d", &n);

    POLY tp = l->link;
    int sum = 0;
    do
    {
        sum += (tp->coeff) * (pow(n, tp->px));
        tp = tp->link;
    } while (tp != l->link);

    return sum;
}

POLY add(POLY l1, POLY l2)
{
    POLY t1 = l1->link;
    POLY t2 = l2->link;
    POLY res = NULL;
    int sum = 0;
    int pow = 0;
    int c1 = cnt(l1), c2 = cnt(l2);
    int n1 = 0, n2 = 0;
    POLY nn = NULL;
    do
    {
        if (t1->px > t2->px)
        {
            sum = t1->coeff;
            pow = t1->px;
            t1 = t1->link;
            n1++;
        }

        else if (t2->px > t1->px)
        {
            sum = t2->coeff;
            pow = t2->px;
            t2 = t2->link;
            n2++;
        }
        else if (t1->px == t2->px)
        {
            sum = t1->coeff + t2->coeff;
            pow = t1->px;
            t1 = t1->link;
            t2 = t2->link;
            n1++;
            n2++;
        }
        if (sum != 0)
        {
            nn = createnode(nn);
            nn->coeff = sum;
            nn->px = pow;
            res = insertrear(res, nn);
        }

    } while (c1 != n1 && c2 != n2);

    POLY t = NULL;
    POLY l = NULL;
    if (t1 != l1->link)
    {
        t = t1;
        l = l1->link;
    }

    if (t2 != l2->link)
    {
        t = t2;
        l = l2->link;
    }
    if (t != NULL)
    {
        do
        {
            POLY nn = createnode(nn);
            nn->coeff = t->coeff;
            nn->px = t->px;
            res = insertrear(res, nn);
            t = t->link;
        } while (t != l);
    }
    return res;
}
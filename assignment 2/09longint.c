//  Design a menu driven program to perform the following with linked list storage structures
// i) Create (Read)a Long positive integer
// ii) Display Long positive integer
// iii) Add two Long positive integers
#include <stdio.h>
#include <stdlib.h>
struct longint
{
    int dig;
    struct longint *link;
};

typedef struct longint *LONG;

void read(LONG);
LONG createheader(LONG);
LONG createnode(LONG);
void disp(LONG);
void insertfront(LONG, LONG);
void add(LONG, LONG, LONG);
void dispsum(LONG);
int main()
{
    int choice;
    LONG header = createheader(header);
    LONG h2 = createheader(h2);
    LONG sum = createheader(sum);

    for (;;)
    {
        printf("\nEnter your choice\n1->read long int\n2->display long int\n3->add two long int\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            read(header);
            break;
        case 2:
            disp(header);
            break;
        case 3:
            printf("Enter another long int to be added\n");
            read(h2);
            add(header, h2, sum);
            printf("Addition of two long int is\n");
            dispsum(sum);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
LONG createheader(LONG h)
{
    LONG header = (LONG)malloc(sizeof(struct longint));
    header->dig = 0;
    header->link = NULL;
    return header;
}

LONG createnode(LONG n)
{
    LONG nn = (LONG)malloc(sizeof(struct longint));
    nn->link = NULL;
    return nn;
}

void insertfront(LONG h, LONG n)
{
    n->link = h->link;
    h->link = n;
    h->dig++;
}

void read(LONG h)
{
    int n;
    for (;;)
    {
        printf("Enter the digits of long int one by one \nenter -1 to stop\n");
        scanf("%d", &n);
        if (n == -1)
            break;
        LONG nn = createnode(nn);
        nn->dig = n;
        insertfront(h, nn);
    }
}

void disp(LONG h)
{
    int n = h->dig;
    printf("Number of digits in long int %d\n", n);
    int *arr = malloc(n * sizeof(int));
    LONG t = h->link;
    int i = 0;
    while (t != NULL)
    {
        *(arr + i) = t->dig;
        i++;
        t = t->link;
    }
    printf("The long int you entered is\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d", *(arr + i));
    }
    printf("\n");
}

void add(LONG h1, LONG h2, LONG h)
{
    int s, c = 0;
    //   LONG h = createheader(h);
    LONG t1 = h1->link;
    LONG t2 = h2->link;
    while (t1 != NULL && t2 != NULL)
    {
        s = (t1->dig + t2->dig + c);
        c = s / 10;
        LONG nn = createnode(nn);
        nn->dig = s % 10;
        insertfront(h, nn);
        t1 = t1->link;
        t2 = t2->link;
    }
    LONG t = NULL;
    if (t1 != NULL)
        t = t1;
    if (t2 != NULL)
        t = t2;

    while (t != NULL)
    {
        s = t->dig + c;
        LONG nn = createnode(nn);
        c = s / 10;
        nn->dig = s % 10;
        insertfront(h, nn);
        t = t->link;
    }

    if (c != 0)
    {
        LONG nn = createnode(nn);
        nn->dig = c;
        insertfront(h, nn);
    }
}

void dispsum(LONG h)
{
    LONG t = h->link;
    while (t != NULL)
    {
        printf("%d", t->dig);
        t = t->link;
    }
    printf("\n");
}
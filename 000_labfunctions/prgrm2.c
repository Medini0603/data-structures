#include <stdio.h>
#include <stdlib.h>

typedef struct time
{
    int h, m, s;
} t;

void read(t *);
void disp(t *);
void update(t *);
void add(t *, t *, t *);
void init(t *);

int main()
{
    t t1, t2, t3;
    int choice;
    for (;;)
    {
        printf("\nEnter your choice\n1->read\n2->display\n3->initialize\n4->update by one sec\n5->add two times\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            read(&t1);
            break;
        case 2:
            disp(&t1);
            break;
        case 3:
            init(&t1);
            disp(&t1);
            break;
        case 4:
            update(&t1);
            disp(&t1);
            break;
        case 5:
            printf("Enter the time to be added\n");
            read(&t2);
            add(&t1, &t2, &t3);
            printf("The two time values that were added are\n");
            disp(&t1);
            disp(&t2);
            printf("THE SUM OF TWO VALUES\n");
            disp(&t3);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}

void read(t *p)
{
    printf("Enter the time in hh:mm:ss format\n");
    scanf("%d:%d:%d", &p->h, &p->m, &p->s);
}

void disp(t *p)
{
    printf("\nTime value : ");
    printf("%d:%d:%d\n", p->h, p->m, p->s);
}

void init(t *p)
{
    p->h = p->m = p->s = 0;
}

void update(t *p)
{
    (p->s)++;
    if (p->s >= 60)
    {
        p->s = p->s % 60;
        (p->m)++;

        if (p->m >= 60)
        {
            p->m = p->m % 60;
            p->h++;
        }

        if (p->h >= 24)
        {
            init(p);
        }
    }
}

void add(t *p1, t *p2, t *p3)
{
    p3->s = p1->s + p2->s;
    p3->m = p1->m + p2->m;
    p3->h = p1->h + p2->h;

    if (p3->s >= 60)
    {
        p3->s = p3->s % 60;
        (p3->m)++;
}

if(p3->m>=60)
{
    p3->m=p3->m%60;
    p3->h++;
}

if(p3->h>=24)
{
    init(p3);
}
}

//void add(t *p1, t *p2, t *p3)
// {
//     p3->s = p1->s + p2->s;
//     p3->m = p1->m + p2->m;
//     p3->h = p1->h + p2->h;

//     if (p3->s >= 60)
//     {
//         p3->s = p3->s % 60;
//         (p3->m)++;

//         if (p3->m >= 60)
//         {
//             p3->m = p3->m % 60;
//             p3->h++;
//         }

//         if (p3->h >= 24)
//         {
//             init(p3);
//         }
//     }

//     if (p3->m >= 60)
//     {
//         p3->m = p3->m % 60;
//         p3->h++;

//         if (p3->h >= 24)
//         {
//             init(p3);
//         }
//     }
//     if (p3->h >= 24)
//     {
//         init(p3);
//     }
// }
#include <stdio.h>
typedef struct queue
{
    int items[20];
    int r, f;
} QUE;

void insert(QUE *q, int n)
{
    q->r++;
    q->items[q->r] = n;
}

void category(QUE *q1, QUE *q2, QUE *q3, QUE *q4, int a)
{
    if (a < 10)
        insert(q1, a);
    if (a >= 10 && a <= 19)
        insert(q2, a);
    if (a > 19 && a <= 29)
        insert(q3, a);
    if (a > 29)
        insert(q4, a);
}

void disp(QUE *q)
{
    if (q->f > q->r)
    {
        printf("Empty\n");
        return;
    }
    for (int i = q->f; i <= q->r; i++)
        printf("%d\t", q->items[i]);
    printf("\n");
}
int main()
{
    QUE q1;
    q1.r = -1;
    q1.f = 0;
    QUE q2;
    q2.r = -1;
    q2.f = 0;
    QUE q3;
    q3.r = -1;
    q3.f = 0;
    QUE q4;
    q4.r = -1;
    q4.f = 0;
    int a[19] = {3, 15, 22, 12, 6, 10, 34, 65, 29, 9, 30, 81, 45, 19, 20, 57, 44, 99, 2};
    int n=sizeof(a)/sizeof(int);
    for (int i = 0; i < n; i++)
        category(&q1, &q2, &q3, &q4, a[i]);
    printf("Category 1\n");
    disp(&q1);
    printf("Category 2\n");
    disp(&q2);
    printf("Category 3\n");
    disp(&q3);
    printf("Category 4\n");
    disp(&q4);
    return 0;
}
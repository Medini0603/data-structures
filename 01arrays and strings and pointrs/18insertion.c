#include <stdio.h>

void read(int[], int );
void disp(int[], int );
void insertbypos(int[], int *);

#define size 10
int main()
{
    int a[size], n;
    printf("Enter the value of n\n");
    scanf("%d", &n);

    read(a, n);
    disp(a, n);
    insertbypos(a,&n);
    disp(a, n);
    return 0;
}
void read(int a[], int n)
{
    printf("Enter the elements one by one\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void disp(int a[], int n)
{
    printf("\nThe elements of the array are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void insertbypos(int a[], int *n)
{
    int pos, element;
    do
    {
        printf("\nEnter a valid position between 1 to %d\n", *n + 1);
        scanf("%d", &pos);
    } while ((pos < 1) || (pos > *n + 1));

    printf("Enter the element to be inserted in position %d\n", pos);
    scanf("%d", &element);

    for (int i = *n - 1; i >= (pos - 1); i--)
    {
        a[i + 1] = a[i];
    }

    a[pos - 1] = element;
   *n=*n+1;
}
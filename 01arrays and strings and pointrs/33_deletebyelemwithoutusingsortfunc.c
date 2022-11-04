#include <stdio.h>
#include <stdlib.h>
void read(int *, int);
void disp(int[], int);
void deletebyelem(int *, int *);
#define size 10
int main()
{
    int a[size], n, choice;
    printf("Enter the number of elements to be processed\n");
    scanf("%d", &n);
    int key;
    for (;;)
    {
        printf("\nEnter your choice\n1 -> read\n2 -> display\n3 -> delete by element\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            read(a, n);
            break;
        case 2:
            disp(a, n);
            break;

        case 3:
            deletebyelem(a, &n);
            disp(a, n);
            break;
            return 0;
        }
    }
}

void read(int *p, int n)
{
    printf("Enter the elements of the array one by one\n");
    for (int i = 0; i < n; i++)
        scanf("%d", (p + i));
}

void disp(int a[], int n)
{
    printf("The elements of the array you entered are\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

void deletebyelem(int *a, int *n)
{
    int key,flag=0;
    if (*n == 0)
    {
        printf("No element to be deleted\n");
        return;
    }
    printf("Enter the element to be deleted\n");
    scanf("%d", &key);
    for (int i = 0;i<*(n);i++)
    {
        if(*(a+i)==key)
        {
            for(int j=i;j<*(n);j++)
                *(a+j)=*(a+j+1);

            *n=*n-1;
            flag=1;
            printf("%d is deleted\n",key);
            break;
        }
       
    }
    if(flag==0)printf("%d not found\n",key);
}
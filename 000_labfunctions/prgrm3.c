#include <stdio.h>
#include<stdlib.h>
void read(int *, int);
void disp(int *, int); 
int search(int *, int, int);
void sort(int *, int);
void insertbypos(int *, int *); 
void deletebypos(int *, int *, int);
void insertbyorder(int *, int *);
void deletebyelem(int *, int *);

int main()
{
    int *a, n, choice,size=5;
    printf("Enter the number of elements to be processed\n");
    scanf("%d", &n);
     a=(int *)malloc(size*sizeof(int));
     int key;
    for (;;)
    {
        printf("\nEnter your choice\n1 -> read\n2 -> display\n3 -> search\n4 -> sort\n5 -> insert by position\n6 -> delete by position\n7 -> insert by order\n8 -> delete by element\n");
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
            printf("Enter the key\n");
            scanf("%d", &key);
            int pos = search(a, n, key);
            if (pos == -1)
                printf("%d not found\n", key);
            else
                printf("%d is found at %d\n", key, pos + 1);
            break;
        case 4:
            sort(a, n);
            printf("The sorted array is\n");
            disp(a, n);
            break;
        case 5:
            if (n == size)
            {
                printf("Array is full\nReallocating\n");
                a=(int *)realloc(a,(size*2)*sizeof(int));
            }
                insertbypos(a, &n);
                printf("The updated array is\n");
            
            disp(a, n);
            break;
        case 6:
            if (n == 0)
                printf("Enter the array is empty\n");
            else
            {
                int pos;
                do
                {
                    printf("\nEnter a valid range between 1 to %d\n", n);
                    scanf("%d", &pos);
                } while ((pos < 1) || (pos > n));

                deletebypos(a, &n, pos);
               
            }
            disp(a, n);
             break;
        case 7:
            if (n == size)
               {
                printf("Array is full\nReallocating\n");
                a=(int *)realloc(a,(size*2)*sizeof(int));
            } 
            
            
                sort(a, n);
                insertbyorder(a, &n);
            
            disp(a, n);
            break;
        case 8:
            if (n == 0)
                printf("Enter the array is empty\n");
            else
                deletebyelem(a, &n);
                disp(a,n);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}

void read(int *p, int n)
{
    printf("Enter the elements of the array one by one\n");
    for (int i = 0; i < n; i++)
        scanf("%d", (p + i));
}

void disp(int *p, int n)
{
    printf("The elements of the array you entered are\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", *(p+i));
}

int search(int *p, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) == key)
        {
            return i;
            break;
        }
       
    }
     return -1;
}

void sort(int *p, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            if (*(p + i) > *(p + i + 1))
            {
                int temp = *(p + i);
                *(p + i) = *(p + i + 1);
                *(p + i + 1) = temp;
            }
        }
    }
}

void insertbypos(int *p, int *n)
{
    int pos, element;
    do
    {
        printf("\nEnter a valid position between 1 to %d\n", *n + 1);
        scanf("%d", &pos);
    } while ((pos < 1) || (pos > *n + 1));

    printf("Enter the element to be inserted\n");
    scanf("%d", &element);
    int i;
    for (i = *n - 1; i >= pos - 1; i--)
    {
        *(p + i + 1) = *(p + i);
    }
    *(p + i + 1) = element;
    *n = *n + 1;
}

void deletebypos(int *p, int *n, int pos)
{
    int i;
    for (i = pos - 1; i < *n - 1; i++)
    {
        *(p + i) = *(p + i + 1);
    }
    *n = *n - 1;
}

void insertbyorder(int *p, int *n)
{
    int element;
    printf("Enter the number you want to insert\n");
    scanf("%d", &element);
    int i;
    for (i = *n - 1; (i >= 0) && (*(p + i) > element); i--)
    {
        *(p + i + 1) = *(p + i);
    }
    *(p + i + 1) = element;
    *n = *n + 1;
}

void deletebyelem(int *p, int *n)
{
    int ele;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    int pos = search(p,*n,ele);
    if(pos==-1)
    {
        printf("Element to be deleted is not found in the array\n");
    }
    else{
        deletebypos(p,n,pos+1);//because we are obtaining the value of index from search,but 
        //in deletebypos we have used position as parameter..
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int rollno;
    float marks[3];
    char name[10];
    float average;
} std;
void read(std *, int);
void disp(std[], int); // just other type
int search(std *, int, int);
void sort(std *, int);
void insertbypos(std *, int *); // int * needed as we are updating n if just int then itll not be updated
void deletebypos(std *, int *, int);
void insertbyorder(std *, int *);
void deletebyelem(std *, int *);
void avg(std *, int);
#define size 10
int main()
{
    std a[size];
    int n, choice;
    printf("Enter the number of elements to be processed\n");
    scanf("%d", &n);
    int key;
    for (;;)
    {
        printf("\nEnter your choice\n1 -> read\n2 -> display\n3 -> search\n4 -> sort\n5 -> insert by position\n6 -> delete by position\n7 -> insert by order\n8 -> delete by element\n9 ->compute average of best of 2\n");
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
            {
                printf("%d is found at %d\n", key, pos + 1);
                printf("\nRollno\t\tName\t\tmarks1\t\tmarks2\t\tmarks3\t\taverage\n");
                printf("\n---------------------------------------------------------------\n");
                printf("%d\t\t", (a + pos)->rollno);
                printf("%s\t\t", (a + pos)->name);
                for (int i = 0; i < 3; i++)
                    printf("%f\t", (a + pos)->marks[i]);
                printf("%d", (a + pos)->average);
                printf("\n---------------------------------------------------------------\n");
            }
            break;
        case 4:
            sort(a, n);
            printf("The sorted array is\n");
            disp(a, n);
            break;
        case 5:
            if (n == size)
                printf("Array is full\nInsertion not possible\n");
            else
            {
                insertbypos(a, &n);
                printf("The updated array is\n");
            }
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
                printf("Array is full\nInsertion not possible\n");
            else
            {
                sort(a, n);
                insertbyorder(a, &n);
            }
            disp(a, n);
            break;
        case 8:
            if (n == 0)
                printf("Enter the array is empty\n");
            else
                deletebyelem(a, &n);
            disp(a, n);
            break;
        case 9:
            avg(a, n);
            disp(a, n);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}

void read(std *p, int n)
{
    printf("\nEnter the elements of the array one by one\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the roll number : ");
        scanf("%d", &(p + i)->rollno);

        printf("\nEnter the name : ");
        scanf("%s", (p + i)->name);
        for (int j = 0; j < 3; j++)
        {
            printf("\nEnter marks %d : ", j + 1);
            scanf("%f", &(p + i)->marks[j]);
        }
    }
}

void disp(std a[], int n)
{
    printf("\nThe elements of the array you entered are\n");
    printf("\nRollno\t\tName\t\tmarks1\t\tmarks2\t\tmarks3\t\taverage\n");
    printf("\n---------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", (a + i)->rollno);
        printf("%s\t\t", (a + i)->name);
        for (int j = 0; j < 3; j++)
            printf("%f\t", (a + i)->marks[j]);
        printf("%f", (a + i)->average);
        printf("\n---------------------------------------------------------------\n");
    }
}

int search(std *p, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if ((p + i)->rollno == key)
        {
            return i;
            break;
        }
    }
    return -1;
}

void sort(std *p, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            if ((p + i)->rollno > (p + i + 1)->rollno)
            {
                std t;
                t = *(p + i);
                *(p + i) = *(p + i + 1);
                *(p + i + 1) = t;
            }
        }
    }
}

void insertbypos(std *p, int *n)
{
    int pos;
    std element;
    do
    {
        printf("\nEnter a valid position between 1 to %d\n", *n + 1);
        scanf("%d", &pos);
    } while ((pos < 1) || (pos > *n + 1));

    printf("Enter the student details to be inserted\n");
    printf("\nEnter the roll number : ");
    scanf("%d", &element.rollno);

    printf("\nEnter the name : ");
    scanf("%s", element.name);
    for (int j = 0; j < 3; j++)
    {
        printf("\nEnter the marks %d : ", j + 1);
        scanf("%f", &element.marks);
    }
    int i;
    for (i = *n - 1; i >= pos - 1; i--)
    {
        *(p + i + 1) = *(p + i);
    }
    *(p + i + 1) = element;
    *n = *n + 1;
}

void deletebypos(std *p, int *n, int pos)
{
    int i;
    for (i = pos - 1; i < *n - 1; i++)
    {
        *(p + i) = *(p + i + 1);
    }
    *n = *n - 1;
}

void insertbyorder(std *p, int *n)
{
    std element;
    printf("Enter the student details you want to insert\n");
    printf("\nEnter the roll number : ");
    scanf("%d", &element.rollno);

    printf("\nEnter the name : ");
    scanf("%s", element.name);
    for (int j = 0; j < 3; j++)
    {
        printf("\nEnter the marks %d : ", j + 1);
        scanf("%f", &element.marks[j]);
    }
    int i;
    for (i = *n - 1; (i >= 0) && ((p + i)->rollno > element.rollno); i--)
    {
        *(p + i + 1) = *(p + i);
    }
    *(p + i + 1) = element;
    *n = *n + 1;
}

void deletebyelem(std *p, int *n)
{
    int element;
    printf("Enter the element to be deleted\n");
    printf("\nEnter the roll number : ");
    scanf("%d", &element);

    int pos = search(p, *n, element);
    if (pos == -1)
    {
        printf("Element to be deleted is not found in the array\n");
    }
    else
    {
        deletebypos(p, n, pos + 1);
    }
}
void avg(std *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum = sum + (p + i)->marks[j];

        int min = (p + i)->marks[0];
        for (int j = 0; j < 3; j++)
        {
            if ((p + i)->marks[j] < min)
            {
                min = (p + i)->marks[j];
            }
        }

        (p + i)->average = (sum - min) / 2;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int rollno;
    float marks;
    char name[10];
} std;
void read(std *, int);
void disp(std[], int); //just other type
int search(std *, int, int);
void sort(std *, int);
void insertbypos(std *, int *); //int * needed as we are updating n if just int then itll not be updated
void deletebypos(std *, int *, int);
void insertbyorder(std *, int *);
void deletebyelem(std *, int *);
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
            {
                printf("%d is found at %d\n", key, pos + 1);
                printf("\nRollno\t\tName\t\tPercentage\t\t\n");
                printf("\n---------------------------------------------------------------\n");
                printf("%d\t\t", (a + pos)->rollno);
                printf("%s\t\t", (a + pos)->name);
                printf("%f\t\t", (a + pos)->marks);
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

        printf("\nEnter the percentage : ");
        scanf("%f", &(p + i)->marks);
    }
}

void disp(std a[], int n)
{
    printf("\nThe elements of the array you entered are\n");
    printf("\nRollno\t\tName\t\tPercentage\t\t\n");
    printf("\n---------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", (a + i)->rollno);
        printf("%s\t\t", (a + i)->name);
        printf("%f\t\t", (a + i)->marks);
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
                int temp = (p + i)->rollno;
                (p + i)->rollno = (p + i + 1)->rollno;
                (p + i + 1)->rollno = temp;

                float tempo = (p + i)->marks;
                (p + i)->marks = (p + i + 1)->marks;
                (p + i + 1)->marks = tempo;

                char tempn[10];
                strcpy(tempn, (p + i)->name);
                strcpy((p + i)->name, (p + i + 1)->name);
                strcpy((p + i + 1)->name, tempn);
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

    printf("\nEnter the percentage : ");
    scanf("%f", &element.marks);

    int i;
    for (i = *n - 1; i >= pos - 1; i--)
    {
        (p + i + 1)->rollno = (p + i)->rollno;
        (p + i + 1)->marks = (p + i)->marks;
        strcpy((p + i + 1)->name, (p + i)->name);
    }
    (p + i + 1)->rollno = element.rollno;
    (p + i + 1)->marks = element.marks;
    strcpy((p + i + 1)->name, element.name);
    *n = *n + 1;
}

void deletebypos(std *p, int *n, int pos)
{
    int i;
    for (i = pos - 1; i < *n - 1; i++)
    {
        (p + i)->rollno = (p + i + 1)->rollno;
        (p + i)->marks = (p + i + 1)->marks;
        strcpy((p + i)->name, (p + i + 1)->name);
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

    printf("\nEnter the percentage : ");
    scanf("%f", &element.marks);
    int i;
    for (i = *n - 1; (i >= 0) && ((p + i)->rollno > element.rollno); i--)
    {
        (p + i + 1)->rollno = (p + i)->rollno;
        (p + i + 1)->marks = (p + i)->marks;
        strcpy((p + i + 1)->name, (p + i)->name);
    }
    (p + i + 1)->rollno = element.rollno;
    (p + i + 1)->marks = element.marks;
    strcpy((p + i + 1)->name, element.name);
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
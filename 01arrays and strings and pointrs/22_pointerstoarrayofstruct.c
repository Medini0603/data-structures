#include <stdio.h>
typedef struct student
{
    int rollno;
    char name[10];
    float per;
} STD;

void read(STD *, int);
void disp(STD[], int);
void search(STD *, int);
// void sort(STD *,int);
// void insert(STD *,int *);
// void delete(STD *,int*);

int main()
{
    STD s[10], *sp;
    int n;
    sp = s;

    printf("Enter the number of students\n");
    scanf("%d", &n);

    read(sp, n);
    disp(s, n);
    search(s,n);
    return 0;
}

void read(STD *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter roll number : ");
        scanf("%d", &(p + i)->rollno);

        printf("\nEnter name : ");
        scanf("%s", (p + i)->name);

        printf("\nEnter percentage : ");
        scanf("%f", &(p + i)->per);
    }
}

void disp(STD s[], int n)
{
    printf("\nRollno\t\tName\t\tpercentage\t\t\n");
    printf("-----------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%s\t\t%f\t\t", (s + i)->rollno, (s + i)->name, (s + i)->per);
        printf("\n------------------------------------------------------");
    }
}

void search(STD *p, int n)
{
    int key, flag = 0;
    printf("\nEnter the roll no to be searched\n");
    scanf("%d", &key);
    STD *lp = p + n - 1;
    for (; p <= lp; p++)
    {
        if (key == (p)->rollno)
        {
            flag = 1;
            printf("%d rollno is found at position\n", key);
            break;
        }
    }
    if (flag == 1)
        {
            printf("\nRollno\t\tName\t\tpercentage\t\t\n");
            printf("-----------------------------------------------------");
            printf("\n%d\t\t%s\t\t%f\t\t", (p)->rollno, (p)->name, (p)->per);
            printf("\n------------------------------------------------------");
        }
        else{printf("\nKey not found\n");}
}
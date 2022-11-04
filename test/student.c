#include <stdio.h>
#include <stdlib.h>

typedef struct stu
{
    int id;
    char name[10];
    int marks[3];
} STD;

void read(STD *s, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("Enter rollno\n");
        scanf("%d", &(s + i)->id);
        printf("Enter name\n");
        scanf("%s", (s + i)->name);
        printf("Enter marks in 3 subjects\n");
        for (j = 0; j < 3; j++)
            scanf("%d", &(s + i)->marks[j]);
    }
}

void disp(STD *a, int n)
{
    printf("\nThe elements of the array you entered are\n");
    printf("\nRollno\t\tName\t\tmarks1\t\tmarks2\t\tmarks3\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", (a + i)->id);
        printf("%s\t\t", (a + i)->name);
        for (int j = 0; j < 3; j++)
            printf("%d\t\t", (a + i)->marks[j]);
            printf("\n");
    }
}

void search(STD *s, int n)
{
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        int max = s->marks[i];
        int pos = 0;
        for (j = 0; j < n; j++)
        {
            if (max < (s + j)->marks[i])
            {
                max = (s + j)->marks[i];
                pos = j;
            }
        }

        printf("Max = %d\n", max);
        printf("Name : %s\n", (s + pos)->name);
        printf("Rollno : %d\n", (s + pos)->id);
        for (k = 0; k < 3; k++)
            printf("%d\t", (s + pos)->marks[k]);
    }
}

void delete(STD *s,int *n)
{
    int i,j;
    int key;
    printf("Enter key\n");
    scanf("%d",&key);
    for(i=0;i<*n;i++)
    {
        if((s+i)->id==key)
        {
            for(j=i;j<*n;j++)
                *(s+j)=*(s+j+1);
            *n=*n-1;
            return;
        }
    }
    printf("Not found no deletion\n");
}

int main()
{
    int n;
    printf("Enter number of students\n");
    scanf("%d",&n);
    STD * s=(STD *)malloc(sizeof(STD)*n);
    int choice;
    for(;;)
    {
        printf("\nEnter choice\n1->read\n2->disp\n3->searchhigh\n4->delete\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:read(s,n);disp(s,n);break;
            case 2:disp(s,n);break;
            case 3:search(s,n);break;
            case 4:delete(s,&n);disp(s,n);break;
            default:exit(0);break;
        }
    }
    return 0;
}
#include<stdio.h>
void read(int[],int *);
void disp(int[],int *);
int main(){
    
    int n,a[10];
    printf("Enter the size of array\n");
    scanf("%d",&n);
    read(a,&n);
    disp(a,&n);
    return 0;
}

void read(int a[],int *n)
{
    int i;
    printf("Enter the values of array one by one\n");
    for(i=0;i<*n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void disp(int a[],int *n)
{
    int i;
    printf("The elements of the array you entered are\n");
    for(i=0;i<*n;i++)
    {
        printf("%d\t",a[i]);
    }
}
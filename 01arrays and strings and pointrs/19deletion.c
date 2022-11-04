#include<stdio.h>
void read(int *p,int);
void disp(int *p,int);
void deletebypos(int *p,int *n);

int main(){
    int a[10],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);

    read(a,n);
    disp(a,n);
    deletebypos(a,&n);
    disp(a,n);

    return 0;
}

void read(int *p,int n){
    printf("Enter the elements one by one\n");
    for(int i=0;i<n;i++)
    scanf("%d",p+i);
}

void disp(int *p,int n){
    printf("The elements of array are\n");
    for(int i=0;i<n;i++){
        printf("%d\t",*(p+i));
    }
}

void deletebypos(int *p,int *n){
    int position;
    do{
        printf("\nEnter a valid range between 1 to %d\n",*n);
        scanf("%d",&position);
    }
    while((position<1)||(position>*n));

    for(int i=position-1;i<=(*n-1);i++)
    {
        *(p+i)=*(p+i+1);
    }
    *n=*n-1;
}
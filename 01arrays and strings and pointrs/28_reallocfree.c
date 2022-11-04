#include<stdio.h>
#include<stdlib.h>
void read(int *,int);
void disp(int *,int);
void insert(int *,int *);
int main(){
    int *p,n;
    n=5;
    p=(int *)malloc(5*sizeof(int));
    read(p,n);
    disp(p,n);
    insert(p,&n);
    free(p);
    return 0;
}
void read(int *p,int n){
    printf("\nEnter the elements one by one\n");
    for(int i=0;i<n;i++)
        scanf("%d",p+i);
}

void disp(int *p,int n){
    printf("\nThe elemnts you entered are\n");
    for(int i=0;i<n;i++)
        printf("%d\t",*(p+i));
}

void insert(int *p,int *n){
    p=(int*)realloc(p,10*sizeof(int));
    int pos,ele;
    printf("\nenter the position to be inserted\n");
    scanf("%d",&pos);
    printf("Enter the element to br inserted\n");
    scanf("%d",&ele);
    int i;
    for( i=4;i>=pos-1;i--){
        *(p+i+1)=*(p+i);
    }
    *(p+i+1)=ele;
    *n=*n+1;
    disp(p,*n);
}
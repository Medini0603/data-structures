#include<stdio.h>
void read(int *p,int);
void disp(int *p,int);
void bubblesort(int *p,int *n);

int main(){
    int a[10],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);

    read(a,n);
    disp(a,n);
    bubblesort(a,&n);
    disp(a,n);

    return 0;
}

void read(int *p,int n){
    printf("Enter the elements one by one\n");
    for(int i=0;i<n;i++)
    scanf("%d",p+i);
}

void disp(int *p,int n){
    printf("\nThe elements of array are\n");
    for(int i=0;i<n;i++){
        printf("%d\t",*(p+i));
    }
}

void bubblesort(int *p,int *n){
   for(int i=0;i<*n-1;i++){
       for(int j=0;j<*n-i-1;j++){
           if(*(p+j)>*(p+j+1))
           {
               int temp = *(p+j);
               *(p+j)=*(p+j+1);
               *(p+j+1)=temp;
           }
       }
   }
}
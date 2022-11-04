#include<stdio.h>
void read(int a[],int n);
void display(int a[],int n);
void reverse(int a[],int n);
void swap(int *a,int *b);
int main(){
    int a[10],b[10],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    reverse(a,n);
      display(a,n);
    return 0;
}

void read(int a[],int n){
    printf("Enter the elements one by one\n");
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    printf("\n");
}

void display(int a[],int n){
    printf("The elements of the array are\n");
    for(int i=0;i<n;i++){
        printf("%d ",*(a+i));
    }
    printf("\n");
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(int a[],int n){
   int *pl,temp;
   pl=a+n-1;

   while(a<pl){
    //    temp=*pa;
    //    *pa=*pl;
    //    *pl=temp;

    //or  

    
    swap(a,pl);
       a++;
       pl--;
   }
}
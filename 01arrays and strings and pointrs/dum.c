#include<stdio.h>
void read(int *p,int n);
void display(int *p,int n);
void reverse(int *pa,int n);

int main(){
    int a[10],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    reverse(a,n);
      display(a,n);
    return 0;
}

void read(int *p,int n){
    printf("Enter the elements one by one\n");
    for(int i=0;i<n;i++){
        scanf("%d",p+i);
    }
    printf("\n");
}

void display(int *p,int n){
    printf("The elements of the array are\n");
    for(int i=0;i<n;i++){
        printf("%d ",*(p+i));
    }
    printf("\n");
}



void reverse(int *pa,int n){
   int *pl,temp;
   pl=pa+n-1;

   while(pa<pl){
       temp=*pa;
       *pa=*pl;
       *pl=temp;

   }
}
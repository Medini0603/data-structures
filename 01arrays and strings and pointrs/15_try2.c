#include<stdio.h>
void read(int a[],int n);
void display(int a[],int n);
void compare(int a[],int b[],int n);
int main(){
    int a[10],b[10],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    read(a,n);
    read(b,n);
    display(a,n);
    display(b,n);
    compare(a,b,n);
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

void compare(int a[],int b[],int n){
    int flag=1;
    for(int i=0;i<n;i++){
        if(*a!=*b){
            flag=0;
            break;
        }
        a++;
        b++;
    }
    if(flag==1){printf("The two arrays are equal\n");}
    else{printf("The two arrays are not equal\n");}
}
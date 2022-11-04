#include<stdio.h>
void read(int *p,int n);
void display(int *p,int n);
void compare(int *pa,int *pb,int n);
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

void compare(int *pa,int *pb,int n){
    int flag=1;
    for(int i=0;i<n;i++){
        if(*(pa+i)!=*(pb+i)){
            flag=0;
            break;
        }
        // pa++;
        // pb++;
    }
    if(flag==1){printf("The two arrays are equal\n");}
    else{printf("The two arrays are not equal\n");}
}
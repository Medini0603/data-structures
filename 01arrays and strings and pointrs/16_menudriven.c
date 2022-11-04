#include<stdio.h>
#include<stdlib.h>
void read(int *p,int n);
void display(int *p,int n);
void search(int *p,int n);
int main(){
    int a[10],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int choice;
    for(;;){
        printf("Enter your choice\n1->read\n2->display\n3->search\nany other number to exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : read(a,n);break;
            case 2 : display(a,n);break;
            case 3 : search(a,n);break;
            default : exit(0);
        }
    }
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

void search(int *p,int n){
    int flag=0,key;
    printf("Enter the key\n");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(key==*(p+i))
        {
            flag=1;
            printf("Key is found at %d\n",i+1);
            break;
        }
    }
    
    if(flag==0){printf("Key not found\n");}
  }
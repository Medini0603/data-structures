#include<stdio.h>

int main(){
    int a[10][10],i,j,r,c;

  
    printf("Enter the number of rows and columns\n",&r,&c);
    scanf("%d%d",&r,&c);
int(*pa)[c];
pa=a;
    printf("Enter the elements one by one\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            int temp=0;
            scanf("%d",&temp);
            *(*(pa+i)+j)=temp;
        }
    }

    printf("the elements of matrix are\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d  ",*(*(pa+i)+j));
        }
        printf("\n");
    }
    return 0;
}
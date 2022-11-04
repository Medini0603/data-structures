#include<stdio.h>

int main(){
    int a[10][10],i,j,r,c,*pa;

    pa=&a[0][0];

    printf("Enter the number of rows and columns\n",&r,&c);
    scanf("%d%d",&r,&c);

    printf("Enter the elements one by one\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",pa+(i*c)+j);
        }
    }

    printf("the elements of matrix are\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d  ",*(pa+(i*c)+j));
        }
        printf("\n");
    }
    return 0;
}
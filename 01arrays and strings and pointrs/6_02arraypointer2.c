#include<stdio.h>

void main(){
    int a[10],*pa,n,i;
    printf("Enter n\n");
    scanf("%d",&n);
    pa=a;
    printf("enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",pa+i);
    }
     for(i=0;i<n;i++){
        printf("%d  ",*(pa+i));
    }
        printf("\n");
     for(pa=a+n-1;pa>=a;pa--){
        printf("%d ",*(pa));
    }
        printf("\n");
}
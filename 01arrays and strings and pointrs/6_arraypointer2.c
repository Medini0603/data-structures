#include<stdio.h>

void main(){
    int a[10],*pa,n;
    printf("Enter n\n");
    scanf("%d",&n);
    pa=a;
    printf("enter the elements\n");
    for(pa=a;pa<a+n;pa++){
        scanf("%d",pa);
    }
     for(pa=a;pa<a+n;pa++){
        printf("%d  ",*pa);
    }
        printf("\n");
     for(pa=a+n-1;pa>=a;pa--){
        printf("%d ",*(pa));
    }
        printf("\n");
}
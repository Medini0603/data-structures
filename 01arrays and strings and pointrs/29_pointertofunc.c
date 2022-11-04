#include<stdio.h>
int max(int , int);
int main(){
    int (*ptr)();//DECLARING
    int a=10,b=100;
    ptr=max;//INITIALIZING
    int large=(*ptr)(a,b);
    printf("Large = %d",large);//DEREFERENCING
    return 0;
}
int max(int x,int y){
    if(x>y)return x;
    else return y;
}
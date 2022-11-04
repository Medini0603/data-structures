#include<stdio.h>
typedef struct student{
    char name[100];
    int marks;
    int rollno;
}st;
int main(){
    st s,*ptr;
    ptr=&s;

    printf("Enter roll number\n");
    scanf("%d",&ptr->rollno);
    return 0;
}
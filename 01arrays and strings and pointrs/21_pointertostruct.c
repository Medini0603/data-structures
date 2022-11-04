#include<stdio.h>
typedef struct student{
    int rollno;
    float marks;
    char name[10];
}STD;
int main(){
    STD s,*sp;
    sp=&s;
    printf("Enter rollno,name,percentage\n");
    scanf("%d %s %f",&sp->rollno,sp->name,&sp->marks);
    printf("You entered\n");
    printf("%d %s %f",sp->rollno,sp->name,sp->marks);
    return 0;
}
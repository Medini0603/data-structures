#include<stdio.h>
#include<string.h>

int main(){
    char name[5][10];//5 names each with 20 letters
    char *p[5];

   for(int i=0;i<5;i++)
   p[i]=name[i];
    printf("Enter 5 names\n");
    for(int i=0;i<5;i++){
        scanf("%s",p[i]);
    }
    printf("The names you entered are\n");
     for(int i=0;i<5;i++){
        printf("%s\n",p[i]);// printf("%s\n",*(p+i+10));
    }
    return 0;
}
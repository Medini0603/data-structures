#include<stdio.h>

void strrem(char*,char*);

int main(){
    char s[10],c;
    printf("Enter the string\n");
    scanf("%s",s);
    printf("Enter the character to be deleted from string\n");
    // char n;
    // scanf("%c",&n);
    fflush(stdin);
    scanf("%c",&c);
    strrem(s,&c);
    printf("%s",s);
    return 0;
}
void strrem(char *s,char *c){
    int i;
    for(i=0;*(s+i)!='\0';i++)
    {
        if(*(s+i)==*c)
        {
            int j;
            for(j=i;*(s+j)!='\0';j++)
            {
               // char temp=*(s+j);
                *(s+j)=*(s+j+1);
               // *(s+j+1)=temp;
            }
           i--;
        }
    }
}
#include <stdio.h>
#include <string.h>

int main()
{
    char name[5][10]; // 5 names each with 20 letters
    char *p;

    p = name[0];
    printf("Enter 5 names\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", p+(10*i));
       
    }
    printf("The names you entered are\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", p+(10*i)); // printf("%s\n",*(p+i+10));
         // NOTE!!!!!---dont use * for %s even in printf
        // think of analogy in without pointer problems
        // there also we just take %s for both printf and scanf
        // there no & in scanf
        // here no * in printf
         
    }
    return 0;
}
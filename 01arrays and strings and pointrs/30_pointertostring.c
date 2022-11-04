#include <stdio.h>
#include<string.h>
int main()
{
    char c = 'c';
    printf("c = %c\n", c);
    char s1[10] = "computer"; // or {'c','o','m','p','u','t','e','r','\0'};
    printf("s1 = %s\n", s1);
    char s2[10];

    //  s2="science";
    // throws error
    strcpy(s2, "science");
    // printf("s2 = %s\n", s2);
    // or
    int i = 0;
    while (s2[i] != '\0')
    {
        printf("%c", s2[i]);
        i++;
    }

    // pointers
    char *ptr;
    ptr = &c;
    printf("\n");
    printf("Enter char c\n");
    scanf("%c", ptr);
    printf("c = %c\n", *ptr);

    ptr = s1;
    ptr = "COMPUTER"; // POSSIBLE
    i = 0;
    while (*(ptr + i) != '\0')
    {
        printf("%c", *(ptr + i));
        i++;
    }
    printf("\n");
    ptr = s2;
    ptr = "SCIENCE_ENG";
    printf("%s", s2);
    return 0;
}
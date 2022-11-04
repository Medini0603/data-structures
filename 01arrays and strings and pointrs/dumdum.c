#include <stdio.h>
void stringcon(char *, char *);
void main()
{
    char s1[30], s2[30];
    printf("\nEnter string 1\n");
    scanf("%s", s1);
    printf("\nEnter string 2\n");
    scanf("%s", s2);
    stringcon(s1, s2);

    printf("\nYour new string is %s\n", s1);
}
void stringcon(char *ps1, char *ps2)
{
    while (*ps1 != '\0')
    {
        ps1++;
    }
    *ps1 = ' ';
     ps1++;
    while (*ps2 != '\0')
    {
        *ps1 = *ps2;
        ps1++;
        ps2++;
    }
    *ps1 = '\0';
}
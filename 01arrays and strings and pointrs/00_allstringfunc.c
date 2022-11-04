#include <stdio.h>
#include <stdlib.h>
void read(char *);
int strlength(char *);
void strreverse(char *);
void strcopy(char *, char *);
void strcon(char *, char *);
void strrem(char *, char);
int main()
{
    char s1[20], s2[10], c;
    printf("\nEnter the string\n");
    scanf("%s", s1);
    int choice, l;
    for (;;)
    {
        printf("\nEnter your choice\n0-->read and change string\n1-->length\n2-->reverse\n3-->copy\n4-->concatenate\n5--.to remove certain character from string\nany other number to end\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            read(s1);
            break;
        case 1:
            l = strlength(s1);
            printf("The length of string is %d", l);
            break;

        case 2:
            strreverse(s1);
            printf("The reversed string is %s", s1);
            break;

        case 3:
            strcopy(s1, s2);
            printf("The original string is %s\n", s1);
            printf("The copied string is %s\n", s2);
            break;

        case 4:
            printf("Enter the string to be concatenated\n");
            scanf("%s", s2);
            strcon(s1, s2);
            printf("The concatenated string is %s\n", s1);
            break;

        case 5:
            printf("Enter the character to be removed from your string\n");
            fflush(stdin);
            scanf("%c", &c);
            strrem(s1, c);
            printf("The updated string is %s", s1);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}
void read(char *p)
{
    printf("Enter the new string\n");
    scanf("%s", p);
}

int strlength(char *p)
{
    int i;
    for (i = 0; *(p + i) != '\0'; i++)
        ;

    return i;
}

void strreverse(char *p)
{
    char *lp;
    lp = p;
    for (int i = 0; *(p + i) != '\0'; i++)
    {
        lp++;
    }
    lp--;
    while (p < lp)
    {
        char temp = *p;
        *(p) = *(lp);
        *lp = temp;
        p++;
        lp--;
    }
}

void strcopy(char *p1, char *p2)
{
    // for(int i=0;*(p1+i)!='\0';i++)
    // {
    //     *(p2)=*(p1+i);
    //     p2++;
    // }
    // *p2='\0';

    while (*p1 != '\0')
    {
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0';
}

void strcon(char *p1, char *p2)
{
    while (*(p1) != '\0')
    {
        p1++;
    }
    *p1=' ';
    p1++;
    while (*p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
}

void strrem(char *p, char c)
{
    int i;
    for (i = 0; *(p + i) != '\0'; i++)
    {
        if (*(p + i) == c)
        {
            {
                for (int j = i; *(p + j) != '\0'; j++)
                    *(p + j) = *(p + j + 1);
            }
            i--;
        }
    }
    *(p+i)='\0';
}
#include <stdio.h>
void towerofhanoi(int n, char s, char t, char d)
{
    if (n == 1)
    {
        printf("Move %d from %c to %c\n", n, s, d);
        return;
    }

    towerofhanoi(n - 1, s, d, t);
    printf("Move %d from %c to %c\n", n, s, d);
    towerofhanoi(n - 1, t, s, d);
}
int main()
{
    int n;
    printf("Enter number of discs\n");
    scanf("%d", &n);
    char source = 's', temp = 't', destination = 'd';
    towerofhanoi(n, source, temp, destination);
    return 0;
}
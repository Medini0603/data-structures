#include <stdio.h>
int count = 0;

int gcd(int m, int n)
{
    count++;
    if (n == 0)
        return m;
    // if(n==m)return m;
    if (n > m)
        return gcd(n, m);
    return gcd(n, m % n);
}
int main()
{
    printf("Enter numbers\n");
    int m, n;
    scanf("%d %d", &m, &n);
    int hcf = gcd(m, n);
    printf("\nGCD = %d\n", hcf);
    printf("Number of calls %d", count);
    return 0;
}
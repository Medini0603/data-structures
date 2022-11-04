#include <stdio.h>
#include <stdlib.h>
int count = 0;
int sum(int arr[], int n)
{
    count++;
    // int n=sizeof(arr)/sizeof(int);
    if (n == 0)
        return arr[n];
    return arr[n] + sum(arr, n - 1);
}
int main()
{
    printf("Enter value of n\n");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    int res = sum(arr, n - 1);
    printf("\nsum = %d\n", res);
    printf("Number of calls %d", count);
    return 0;
}
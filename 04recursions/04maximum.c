#include <stdio.h>
#include <stdlib.h>
int count = 0;
int max(int arr[], int n)
{
    int large;
    count++;
    // int n=sizeof(arr)/sizeof(int);
    if (n == 0)
        return arr[n];
    large = max(arr, n - 1);
    if (large > arr[n])
        return large;
    else
        return arr[n];
}
int main()
{
    printf("Enter value of n\n");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    int res = max(arr, n - 1);
    printf("\nmax = %d\n", res);
    printf("Number of calls %d", count);
    return 0;
}
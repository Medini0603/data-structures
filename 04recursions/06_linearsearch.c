#include <stdio.h>
#include <stdlib.h>
int count = 0;

int linearsearch(int arr[], int n, int key)
{
    count++;
    if (n >= 0)
    {
        if (arr[n] == key)
            return n+1;

        return linearsearch(arr, n - 1, key);
    }
    return -1;
}
int main()
{
    printf("Enter value of n\n");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    printf("Enter key\n");
    int key;
    scanf("%d", &key);
    int pos = linearsearch(arr, n - 1, key);
    printf("\nposition = %d\n", pos);
    printf("Number of calls %d", count);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int count = 1;

int binarysearch(int arr[], int l, int h, int key)
{
    count++;
    int m;
    if (l > h)
        return -1;
    m = (l + h) / 2;
    if (arr[m] == key)
        return m + 1;
    if (arr[m] > key)
        return binarysearch(arr, l, m - 1, key);
    return binarysearch(arr, m + 1, h, key);
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
    int low = 0;
    int high = n - 1;
    int pos = binarysearch(arr, low, high, key);
    printf("\nposition = %d\n", pos);
    printf("Number of calls %d", count);
    return 0;
}
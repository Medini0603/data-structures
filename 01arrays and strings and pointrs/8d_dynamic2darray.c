#include <stdio.h>

int main()
{
    int i, j, r, c;

    printf("Enter the number of rows and columns\n", &r, &c);
    scanf("%d%d", &r, &c);
    int **arr = malloc(c * sizeof(int));
    printf("Enter the elements one by one\n");
    for (i = 0; i < r; i++)
    {
        int *((arr )+ i) = malloc(r * sizeof(int));
        for (j = 0; j < c; j++)
        {
            int temp = 0;
            scanf("%d", &temp);
            *(*(arr + i) + j) = temp;
        }
    }

    printf("the elements of matrix are\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return 0;
}
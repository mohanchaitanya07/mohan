#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j;
    printf("enter order of matrix");
    scanf("%d", &n);                    // as it is symmetric which is  square matrix order is same
    int elements = ((n * (n + 1)) / 2); // 1+2+3+4+5....=(n(n+1)/2)
    int *matrix = (int *)malloc(elements * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            *((matrix + j) + (i * n)) = rand() % 100;
        }
    }
    // loops for printing upper triangular elements in lower triangular positions
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            *((matrix + i) + (j * n)) = *((matrix + j) + (i * n));
        }
    }
    printf("symmetric matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *((matrix + j) + (i * n)));
        }
        printf("\n");
    }
    return (0);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, flag, p;
    printf("enter the size of array\n");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    printf("elements of array\n");
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 1000;
        printf("%d ", array[i]);
    }
    int i = 0;
    for (i = 1; i < (n / 2); i = i + 2)
    {
        int flag = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = flag;

        printf("\niteration-%d", p = (i + 1) / 2);
        for (int j = 0; j < n; j++)
            printf("\t%d", array[j]);
    }
    printf("\nno of operations performed is same as number of iteraions---:%d", p);
}
#include <stdio.h>
#include <stdlib.h>
int powerfn_(int base, int power);
int *del_gptermfn(int place, int size, int *array);
int operations = 0;
int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    printf("elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 1000;
        printf("%d ", array[i]);
    }
    int i;
    for (i = 0; powerfn_(2, i) < n; ++i)
    {
        int *flag = del_gptermfn(powerfn_(2, i), n, array);
        --n;
        free(array);
        array = flag;
    }
    printf("\nfinal answer is:");
    for (i = 0; i < n; ++i)
    {
        printf("\t%d", array[i]);
    }
    printf("\nno of operations performed is %d\n", operations);
    free(array);
}
int powerfn_(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return base * powerfn_(base, power - 1);
}
int *del_gptermfn(int position, int size, int *array)
{
    int *flag = (int *)malloc((size - 1) * sizeof(int));
    int j = 0;
    for (int i = 0; i < size; ++i)
    {
        operations++;
        if (i == position)
        {
            continue;
        }
        flag[j++] = array[i];
    }
    return flag;
}
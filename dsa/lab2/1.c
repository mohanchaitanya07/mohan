#include <stdio.h>
#include <stdlib.h>
int binary_operations = 0;
int binarysearch(int first, int last, int s, int *array);
int main()
{
    int n, i, s, operation;
    printf("enter size of array\n");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    printf("enter elements of array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("enter element to search:");
    scanf("%d", &s);
    int c = -1;
    for (i = 0; i < n; i++)
        if (array[i] == s)
        {
            c = i + 1;
            break;
        }
    if (c > 0)
    {
        printf("element found ");
        printf("the number of operations performed in linear search is:%d\n", c);
    }
    else
    {
        printf("element not found");
        printf("the number of operations performed in linear search is:%d\n", n);
    }
    int found = binarysearch(0, n - 1, s, array);
    if (found)
    {
        printf("search element found\n");
        printf("the number of operations performed in binary search is:%d\n", binary_operations);
    }
    else
    {
        printf("search elemement not found in binary search");
    }
    return (0);
}
int binarysearch(int first, int last, int s, int *array)
{
    binary_operations++;
    int middle = (first + last) / 2;

    if (array[middle] == s)
    {
        return 1;
    }
    else if (array[middle] > s)
    {
        return binarysearch(first, middle - 1, s, array);
    }
    else if (array[middle] < s)
    {
        return binarysearch(middle + 1, last, s, array);
    }
    else
    {
        return (0);
    }
}
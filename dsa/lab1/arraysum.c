#include <stdio.h>
void main()
{
int a[50], i, n, sum = 0;
printf("enter the number of elements to be stored in the array :");
    scanf("%d", &n);
printf("enter %d elements in array :\n", n);
for (i = 0; i < n; i++)
    {
        printf("element - %d :", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        sum += a[i];
    }
    printf("Sum of total elements stored in the array is : %d\n", sum);
}

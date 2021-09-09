#include <stdio.h>
#include <stdlib.h>
typedef node
{
    int number;
    node *next;
}
node;
int main()
{
    long int n;
    printf("Enter the number of nodes: ");
    scanf("%ld", &n);
    int first = 0, second = 1;
    int evensum = 0, oddsum = 0;
    node *head = (node *)malloc(sizeof(node));
    if (head == NULL) // memory allocation checking
    {
        printf("no memory allocated");
        return 1;
    }
    head->number = second;
    head->next = NULL;
    for (int i = 0; i < n; i++)
    {
        if (head->number % 2 == 1)
            oddsum += head->number;
        else
            evensum += head->number;

        node *temp = (node *)malloc(sizeof(node));
        if (temp == NULL) // memory allotment checking
        {
            printf("no memory allocated");
            return 1;
        }
        int fibo = second;
        second = first + second;
        first = fibo;

        temp->number = second;
        temp->next = NULL;

        head->next = temp;
        head = head->next;
    }
    node *flag = head;
    node *next;

    while (flag != NULL)
    {
        next = flag->next;
        free(flag);
        flag = next;
    }
    printf("even numbers sum in the series is: %d\n", evensum);
    printf("odd numbers sum in the series is: %d\n", oddsum);
}

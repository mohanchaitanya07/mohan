#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int number;
    struct stack *next;
} stack;
void pushfn(stack **flag, int number);
void popfn(stack **flag);
void print(stack *head);
int main()
{
    unsigned int n;
    long long int factorial = 1;
    stack *head = NULL;
    printf("enter a positive integer:- ");
    scanf("%d", &n);
    for (int i = n; i >= 1; --i)
    {
        pushfn(&head, i);
    }
    printf("values stored in the stack are:-");
    print(head);
    while (head != NULL)
    {
        factorial = factorial * (head->number);
        popfn(&head);
    }
    printf("\nfactorial of %d is %lld\n", n, factorial);
}
void pushfn(stack **flag, int number) //headreference = flag
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->number = number;
    temp->next = *flag;
    *flag = temp;
}
void popfn(stack **flag)
{
    stack *temp = *flag;
    *flag = temp->next;
    free(temp);
}
void print(stack *head)
{
    while (head != NULL)
    {
        printf(" %d ", head->number);
        head = head->next;
    }
}

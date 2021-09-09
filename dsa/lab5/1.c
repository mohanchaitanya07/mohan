#include <stdio.h>
#include <stdlib.h>
typedef node
{
    float f;
    node *next;
}
node;
void linkedlist(node *head, unsigned int n);
void print(node *head);
void revlinkedlist(node *head, int gpfactor, int n);
int main()
{
    unsigned int n, gpfactor;
    printf("enter the number of nodes:-\t");
    scanf("%d", &n);
    printf("enter the factor of gp series:-\t");
    scanf("%d", &gpfactor);
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        printf("no memory allocated");
        exit(0);
    }
    linkedlist(head, n);
    printf("Generated floating values are:\n");
    print(head);
    revlinkedlist(head, gpfactor, n);
    printf("\nReversed floating values are:\n");
    print(head);
    printf("\n");
}
void linkedlist(node *head, unsigned int n)
{
    float floatvalue = (rand() % 10000) * 0.001;
    head->f = floatvalue;
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        float floatvalue = (rand() % 10000) * 0.01;
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("no memory allocated");
            exit(0);
        }
        head->next = temp;
        head = head->next;
        head->f = floatvalue;
        head->next = NULL;
    }
}
void print(node *head)
{
    while (head != NULL)
    {
        printf(" %f ", head->f);
        head = head->next;
    }
}
void revlinkedlist(node *head, int gpfactor, int n)
{
    int sum, term, i;
    node *start = head;
    node *actual_start = head->next;
    sum = 1 + gpfactor;
    for (term = gpfactor; sum <= n; term = term * gpfactor, sum += term)
    {
        node *current = actual_start;
        node *prev = NULL, *next = NULL;
        for (i = 0; i < term; ++i)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        start->next = prev;
        actual_start->next = next;
        start = actual_start;
        actual_start = actual_start->next;
    }
}

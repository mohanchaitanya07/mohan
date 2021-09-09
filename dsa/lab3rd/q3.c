#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
//typedef is used here,otherwise struct node should  be written everytime
{
    int number;
    node *next;
} node;
void list(node *head);
void print(node *head);
int main()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    if (head == NULL) // memory allocation checking
    {
        printf("no memory allocated");
        exit(1);
    }
    list(head);
    print(head);
}
void list(node *head)
{
    char c;
    printf("enter number-%d\t", 1);
    scanf("%d", &head->number);
    head->next = NULL;
    int i = 2;
    printf("press anything to continue or press q to quit\t");
    scanf("\n%c", &c);
    while (c != 'q')
    {
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("no memory allocated");
            exit(1);
        }
        head->next = temp;
        head = head->next;
        printf("enter element-%d\t", i++);
        scanf("%d", &head->number);
        head->next = NULL;
        printf("press anything to continue or press q to quit\t");
        scanf("\n%c", &c);
    }
}
void print(node *head)
{
    printf("elements are:\n");
    int sum = 0, squaresum = 0;
    int count = 0;
    float mean, stddev;
    while (head != NULL)
    {
        count++;
        node *temp;
        temp = head->next;
        printf("\t%d", head->number);
        sum += head->number;
        squaresum += (head->number) * (head->number);
        free(head);
        head = temp;
    }
    printf("\ncount is:%d\n", count);
    mean = (float)sum / count;
    printf("mean is:%f\n", mean);
    stddev = sqrt(((squaresum) / count) - (mean * mean));
    printf("standard deviation is:%f\n", stddev);
}
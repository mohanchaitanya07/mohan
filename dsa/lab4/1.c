#include <stdio.h>
#include <stdlib.h>
unsigned int n;
typedef node
{
    char c;
    node *next;
}
node;
void llist(node *head, unsigned int n);
void print(node *head);
void dupl_del(node *head);
int main()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        printf("no memory allocated");
        exit(1);
    }
    llist(head, n);
    print(head);
    dupl_del(head);
    print(head);
}
void llist(node *head, unsigned int n)
{
    printf("enter number of nodes:");
    scanf("%u", &n);
    char character = 'a' + (rand() % 26);
    head->c = character;
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        char character = 'a' + (rand() % 26);
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("no memory allocated");
            exit(1);
        }
        head->next = temp;
        head = head->next;
        head->c = character;
        head->next = NULL;
    }
}
void print(node *head)
{
    printf("characters are:\n");
    for (head; head != NULL; head = head->next)
    {
        printf("\t%c", head->c);
    }
}
void dupl_del(node *head)
{
    node *temp;
    node *del;
    node *remember;
    printf("\ndel_gptermd duplicate elements............now ");
    for (head; head != NULL; head = head->next)
    {
        remember = head;
        for (temp = head->next; temp != NULL; temp = temp->next)
        {
            if (head->c == temp->c)
            {
                del = temp;
                remember->next = temp->next;
                free(del);
            }
            else
            {
                remember = remember->next;
            }
        }
    }
}
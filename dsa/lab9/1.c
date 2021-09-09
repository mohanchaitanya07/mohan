#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char *month;
    struct node *next;
    struct node *prev;
} node;
int count = 1;
void createfn(node *head);
node *sortnode2bst(node **head, int n);
void printfn(node *head);
void inorder(node *root);
int main()
{
    node *head = (node *)malloc(sizeof(node));
    createfn(head);
    node *root = sortnode2bst(&head, 12);
    printf("\nINORDER TRAVERSAL: \n");
    inorder(root);
    printf("\n");
    return 0;
}
char *mon(int i)
{
    switch (i)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        return "error-no-month";
        break;
    }
}
void createfn(node *head)
{
    head->prev = NULL;
    head->month = mon(count);
    ++count;
    head->next = NULL;
    while (count <= 12)
    {
        node *temp = (node *)malloc(sizeof(node));
        head->next = temp;
        temp->prev = head;
        temp->month = mon(count);
        temp->next = NULL;
        head = temp;
        ++count;
    }
}
node *sortnode2bst(node **head, int n)
{
    if (n <= 0)
        return NULL;
    node *left = sortnode2bst(head, n / 2);
    node *root = *head;
    root->prev = left;
    *head = (*head)->next;
    root->next = sortnode2bst(head, n - n / 2 - 1);
    return root;
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->prev);
        printf(" \t\t%s \n", root->month);
        inorder(root->next);
    }
}
void printfn(node *head)
{
    while (head != NULL)
    {
        printf(" %s ", head->month);
        head = head->next;
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char ch;
    struct node *left;
    struct node *right;
} node;
typedef struct queue
{
    struct node *node_ptr;
    struct queue *next;
} queue;
node *root = NULL;
queue *FRONT = NULL;
queue *REAR = NULL;
void free_tree(node *root);
void free_list();
void enqueue(node *node_ptr);
void dequeue();
void create();
void preOrder(node *root);
void inOrder(node *root);
void postOrder(node *root);
int main()
{
    create();
    printf("\nPreorder : ");
    preOrder(root);
    printf("\nPostorder: ");
    postOrder(root);
    printf("\nInOrder : ");
    inOrder(root);
    printf("\n");
    free_list();
    free_tree(root);
}
void free_list()
{
    while (FRONT != NULL)
    {
        queue *tmp = FRONT->next;
        free(FRONT);
        FRONT = tmp;
    }
}
void free_tree(node *root)
{
    if (root != NULL)
    {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
void enqueue(node *node_ptr)
{
    if (FRONT == NULL)
    {
        queue *tmp = (queue *)malloc(sizeof(queue));
        tmp->node_ptr = node_ptr;
        tmp->next = NULL;
        FRONT = tmp;
        REAR = tmp;
    }
    else
    {
        queue *tmp = (queue *)malloc(sizeof(queue));
        tmp->node_ptr = node_ptr;
        tmp->next = NULL;
        REAR->next = tmp;
        REAR = tmp;
    }
}
void dequeue()
{
    if (FRONT != NULL)
    {
        queue *tmp = FRONT;
        FRONT = FRONT->next;
        free(tmp);
    }
}
void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%c", root->ch);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%c", root->ch);
        inOrder(root->right);
    }
}
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c", root->ch);
    }
}
void create()
{
    root = (node *)malloc(sizeof(node));
    root->ch = 'A';
    enqueue(root);
    for (char ch = 'B'; ch <= 'Z'; ch++)
    {
        node *cur_root = FRONT->node_ptr;
        if (cur_root->left == NULL)
        {
            node *tmp = (node *)malloc(sizeof(node));
            tmp->ch = ch;
            tmp->left = NULL;
            tmp->right = NULL;
            cur_root->left = tmp;
            enqueue(tmp);
        }
        else if (cur_root->right == NULL)
        {
            node *tmp = (node *)malloc(sizeof(node));
            tmp->ch = ch;
            tmp->left = NULL;
            tmp->right = NULL;
            cur_root->right = tmp;
            enqueue(tmp);
            dequeue();
        }
    }
}
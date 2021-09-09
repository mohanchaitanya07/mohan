#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct tree
{
    char data;
    struct tree *left;
    struct tree *right;
} tree;
typedef struct queue
{
    struct tree *address;
    struct queue *next;
} queue;
queue *front = NULL;
queue *rear = NULL;
void enqueue(tree *node);
tree *dequeue();
tree *createfn(tree *node);
void preorder(tree *root);
void inorder(tree *root);
void postorder(tree *root);
void print();
int main()
{
    srand(time(NULL));
    tree *root = (tree *)malloc(sizeof(tree));
    root = createfn(root);
    printf("---------------------------------Pre-order:----------------------------------\n\n");
    preorder(root);
    printf("\n\n-----------------------------------In-order:------------------------------------\n\n");
    inorder(root);
    printf("\n\n----------------------------------Post-order:-----------------------------------\n\n");
    postorder(root);
    printf("\n");
    return 0;
}
void enqueue(tree *node)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->address = node;
    if (front == NULL)
    {
        front = rear = temp;
        front->next = rear->next = NULL;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = NULL;
    }
}
tree *dequeue()
{
    if (front == NULL)
    {
        printf("Underflow!!!");
        exit(0);
    }
    else
    {
        tree *temp = (tree *)malloc(sizeof(tree));
        temp = front->address;
        front = front->next;
        return temp;
    }
}
tree *createfn(tree *node)
{
    int i = 0;
    tree *root = node;
    node->data = 65 + i;
    ++i;
    enqueue(node);
    while (i < 26)
    {
        print();
        node = dequeue();
        print();
        tree *temp_left = (tree *)malloc(sizeof(tree));
        node->left = temp_left;
        node->left->data = 65 + i;
        ++i;
        enqueue(node->left);
        if (i < 26)
        {
            tree *temp_right = (tree *)malloc(sizeof(tree));
            node->right = temp_right;
            node->right->data = 65 + i;
            ++i;
            enqueue(node->right);
        }
    }
    printf("\n");
    return root;
}
void preorder(tree *root)
{
    if (root != NULL)
    {
        printf(" %c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %c ", root->data);
        inorder(root->right);
    }
}
void postorder(tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %c ", root->data);
    }
}
void print()
{
    queue *temp = front;
    while (temp != NULL)
    {
        temp = temp->next;
    }
}

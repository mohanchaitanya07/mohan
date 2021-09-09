#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct tree
{
    char data;
    struct tree *leftchild;
    struct tree *rightchild;
} tree;
typedef struct queue
{
    struct tree *address;
    struct queue *next;
} queue;
queue *front = NULL;
queue *rear = NULL;
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
        printf("Underflow");
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
void print_queue()
{
    queue *temp = front;
    while (temp != NULL)
    {
        temp = temp->next;
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
        print_queue();
        node = dequeue();
        print_queue();
        tree *temp_left = (tree *)malloc(sizeof(tree));
        node->leftchild = temp_left;
        node->leftchild->data = 65 + i;
        ++i;
        enqueue(node->leftchild);
        if (i < 26)
        {
            tree *temp_right = (tree *)malloc(sizeof(tree));
            node->rightchild = temp_right;
            node->rightchild->data = 65 + i;
            ++i;
            enqueue(node->rightchild);
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
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}
void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        printf(" %c ", root->data);
        inorder(root->rightchild);
    }
}
void postorder(tree *root)
{
    if (root != NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf(" %c ", root->data);
    }
}
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
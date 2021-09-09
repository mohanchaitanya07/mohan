#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct t_node
{
    char *month;
    struct t_node *right;
    struct t_node *left;
} t_node;
t_node *head = NULL;
t_node *tail = NULL;
t_node *root = NULL;
typedef struct queue
{
    struct t_node *node_ptr;
    struct queue *next;
} queue;
queue *FRONT = NULL;
queue *REAR = NULL;
t_node *dummy = NULL;
void print_hash(char *x);
void printspace(int n);
void printtree(t_node *root, int height);
int power(int base, int power);
void enqueue(t_node *node_ptr);
void dequeue();
void create_list();
int create_tree(t_node *front, t_node *rear, t_node **des_ptr);
void inorder(t_node *root);
int main()
{
    t_node *dummy = (t_node *)malloc(sizeof(t_node));
    dummy->month = NULL;
    dummy->left = NULL;
    dummy->right = NULL;
    create_list();
    t_node *d_head = head;
    t_node *d_tail = tail;
    create_tree(head, tail, &root);
    printf("In-order traversal: ");
    inorder(root);
    printf("\nTree representation: \n");
    printtree(root, 4);
}
void print_hash(char *x)
{
    int a = 10;
    int length = strlen(x);
    int dif = a - length;
    if (dif & 1)
    {
        for (int i = 0; 2 * i < dif - 1; i++)
        {
            printf("#");
        }
        printf("%s", x);
        for (int i = 0; 2 * i < (dif + 1); i++)
        {
            printf("#");
        }
    }
    else
    {
        for (int i = 0; i < dif; i = i + 2)
        {
            printf("#");
        }
        printf("%s", x);
        for (int i = 0; i < dif; i = i + 2)
        {
            printf("#");
        }
    }
}
int power(int base, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result = result * base;
    }
    return result;
}
void printspace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}
void printtree(t_node *root, int height)
{
    printspace(5 * (power(2, height) - 1));
    print_hash(root->month);
    printf("\n");
    enqueue(root);
    int no_of_iter = power(2, height - 1) - 1;
    int d_height = height - 1;
    int count = 0;
    for (int i = 0; i < no_of_iter; i++)
    {
        count++;
        if (FRONT->node_ptr->left == NULL || FRONT->node_ptr->left->month == NULL)
        {
            printspace((5 * (power(2, d_height) - 1)));
            printspace(10);
            printspace((5 * (power(2, d_height) - 1)));
            enqueue(dummy);
        }
        else
        {
            printspace((5 * (power(2, d_height) - 1)));
            print_hash(FRONT->node_ptr->left->month);
            printspace((5 * (power(2, d_height) - 1)));
            enqueue(FRONT->node_ptr->left);
        }
        if (FRONT->node_ptr->right == NULL || FRONT->node_ptr->right->month == NULL)
        {
            printspace((5 * (power(2, d_height) - 1)));
            printspace(10);
            printspace((5 * (power(2, d_height) - 1)));
            enqueue(dummy);
        }
        else
        {
            printspace((5 * (power(2, d_height) - 1)));
            print_hash(FRONT->node_ptr->right->month);
            printspace((5 * (power(2, d_height) - 1)));
            enqueue(FRONT->node_ptr->right);
        }
        dequeue();
        if (count == power(2, (height - d_height - 1)))
        {
            count = 0;
            printf("\n");
            d_height--;
        }
    }
}
void enqueue(t_node *node_ptr)
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
void inorder(t_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->month);
        inorder(root->right);
    }
}
int create_tree(t_node *d_front, t_node *d_rear, t_node **des_ptr)
{
    if (d_front == NULL || d_rear == NULL)
    {
        return 0;
    }
    else
    {
        t_node *front = d_front;
        t_node *rear = d_rear;
        while (1)
        {
            if (front == rear || front == rear->left)
            {
                break;
            }
            front = front->right;
            rear = rear->left;
        }
        (*des_ptr) = front;
        if ((*des_ptr)->left != NULL)
            (*des_ptr)->left->right = NULL;
        if ((*des_ptr)->right != NULL)
            (*des_ptr)->right->left = NULL;
        create_tree(d_front, front->left, &((*des_ptr)->left));
        create_tree(front->right, d_rear, &((*des_ptr)->right));
        return 0;
    }
}
void create_list()
{
    char *month[12] = {"January", "February", "March", "April", "May",
                       "June", "July", "August", "September", "October", "November", "December"};
    int lenght = strlen(month[0]);
    char *str = (char *)malloc(lenght * sizeof(char));
    strcpy(str, month[0]);
    head = (t_node *)malloc(sizeof(t_node));
    tail = head;
    head->month = str;
    head->left = NULL;
    head->right = NULL;
    for (int i = 1; i < 12; i++)
    {
        int lenght = strlen(month[i]);
        char *str = (char *)malloc(lenght * sizeof(char));
        strcpy(str, month[i]);
        t_node *tmp = (t_node *)malloc(sizeof(t_node));
        tmp->month = str;
        tmp->left = tail;
        tmp->right = NULL;
        tail->right = tmp;
        tail = tmp;
    }
}
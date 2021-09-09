#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
} bst;
bst *parent = NULL;
bst *locn = NULL;
int count = 0;
void inorder(bst *root);
bst *right_rotn(bst *y);
bst *left_rotn(bst *x);
bst *ins_avl(bst *node, int data);
bst *newNode(int data);
void find(bst *root, int item);
int getBalance(bst *node);
void ins_bst(bst *root, int item, int *store);
int height(bst *node);
int main()
{
    int n;
    srand(time(NULL));
    bst *root_bst = (bst *)malloc(sizeof(bst));
    bst *root_avl = NULL;
    printf("Enter no of nodes(for creation of tree):- ");
    scanf("\t%d", &n);
    int store[n];
    parent = root_bst;
    root_bst->data = rand() % 1000;
    store[count] = root_bst->data;
    ++count;
    printf("\n Stored data: \n");
    for (int i = 1; i < n; ++i)
    {
        printf(" %d ", store[i - 1]);
        ins_bst(root_bst, rand() % 1000, store);
    }
    printf(" %d ", store[count - 1]);
    printf("\n BST: \n");
    inorder(root_bst);
    for (int i = 0; i < n; ++i)
    {
        root_avl = ins_avl(root_avl, store[i]);
    }
    printf("\n");
    printf(" AVL: \n");
    inorder(root_avl);
    printf("\n Height of BS tree: %d\n", height(root_bst));
    printf("Height of AVL tree: %d\n", height(root_avl));
    printf("Height difference(BS-AVL) = %d\n\n", height(root_bst) - height(root_avl));
    return 0;
}
void find(bst *root, int item)
{
    bst *save = NULL;
    bst *ptr = NULL;
    int flag = 1;
    if (root == NULL)
    {
        locn = NULL;
        parent = NULL;
    }
    else if (item == root->data)
    {
        locn = root;
        parent = NULL;
        flag = 0;
    }
    else if (flag == 1)
    {
        if (item < root->data)
        {
            ptr = root->left;
            save = root;
        }
        else
        {
            ptr = root->right;
            save = root;
        }
        parent = save;
        while (ptr != NULL)
        {
            if (item == ptr->data)
            {
                locn = ptr;
                parent = save;
                flag = 0;
            }
            else if (item < ptr->data)
            {
                save = ptr;
                ptr = ptr->left;
            }
            else
            {
                save = ptr;
                ptr = ptr->right;
            }
        }
    }
    if (flag == 1)
    {
        locn = NULL;
        parent = save;
    }
}
void ins_bst(bst *root, int item, int *store)
{
    find(root, item);
    *(store + count) = item;
    ++count;
    if (locn != NULL)
    {
        printf("\ndata is already there\n");
    }
    else
    {
        bst *new = (bst *)malloc(sizeof(bst));
        new->data = item;
        new->left = NULL;
        new->right = NULL;
        locn = new;
        if (parent == NULL)
        {
            root = new;
            printf("root: %d\n", root->data);
        }
        else if (item < parent->data)
        {
            parent->left = new;
        }
        else
        {
            parent->right = new;
        }
    }
}
int height(bst *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left_height = height(node->left);
        int right_height = height(node->right);
        if (left_height > right_height)
            return (left_height + 1);
        else
            return (right_height + 1);
    }
}

bst *right_rotn(bst *y)
{
    bst *x = y->left;
    bst *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
bst *left_rotn(bst *x)
{
    bst *y = x->right;
    bst *T2 = y->left;
    x->right = T2;
    return y;
}
int getBalance(bst *node)
{
    if (node == NULL)
        return 0;
    return (height(node->left)) - (height(node->right));
}
bst *newNode(int data)
{
    bst *node = (bst *)malloc(sizeof(bst));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
bst *ins_avl(bst *node, int data)
{
    if (node == NULL)
        return (newNode(data));
    if (data < node->data)
        node->left = ins_avl(node->left, data);
    else if (data > node->data)
        node->right = ins_avl(node->right, data);
    else
        return node;

    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return right_rotn(node);
    if (balance < -1 && data > node->right->data)
        return left_rotn(node);
    if (balance > 1 && data > node->left->data)
    {
        node->left = left_rotn(node->left);
        return right_rotn(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = right_rotn(node->right);
        return left_rotn(node);
    }
    return node;
}
void inorder(bst *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

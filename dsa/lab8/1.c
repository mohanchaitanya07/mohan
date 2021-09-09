#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct tree
{
    int number;
    struct tree *left;
    struct tree *right;
} tree;
tree *binarytree();
void preorder(tree *node);
void inorder(tree *node);
void postorder(tree *node);
int n;
int sum = 0;
float mean, stddev = 0.0;
int main()
{
    tree *root = binarytree();
    root->left = binarytree();
    root->right = binarytree();
    root->left->left = binarytree();
    root->left->right = binarytree();
    root->right->left = binarytree();
    root->right->right = binarytree();
    mean = sum / n;
    printf("pre-order traversing :-\t");
    preorder(root);
    printf("\nAfter pre-order traversing ------------------>mean=%f and stddev=%f  ", mean, stddev);
    printf("\nin-order trversing   :-\t");
    inorder(root);
    printf("\nAfter in-order traversing--------------------->mean=%f and stddev=%f ", mean, stddev);
    printf("\npost-order traversing:-\t");
    postorder(root);
    printf("\nAfter post-order traversing-------------------->mean=%f and stddev=%f\n ", mean, stddev);
    return 0;
}
tree *binarytree()
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->number = rand() % 1000;
    temp->left = NULL;
    temp->right = NULL;
    sum += temp->number;
    n++;
    return temp;
}
void preorder(tree *node)
{
    stddev = 0;
    if (node)
    {
        printf(" %d ", node->number);
        preorder(node->left);
        preorder(node->right);
        stddev += pow((node->number - mean), 2);
    }
    stddev = sqrt(stddev / n);
}
void inorder(tree *node)
{
    stddev = 0;
    if (node)
    {
        inorder(node->left);
        printf(" %d ", node->number);
        inorder(node->right);
        stddev += pow((node->number - mean), 2);
    }
    stddev = sqrt(stddev / n);
}
void postorder(tree *node)
{
    stddev = 0;
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        printf(" %d ", node->number);
        stddev += pow((node->number - mean), 2);
    }
    stddev = sqrt(stddev / n);
}

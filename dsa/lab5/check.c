#include <stdio.h>
#include <stdlib.h>
#include <math.h>
list
{
    int data;
    list *backward;
    list *forward;
}
*last;

void createlist(list *node, int n);
void del_gpterm_nodes(list *head, int n, int f);
void TraverseList(list *head, int f, int n);

int main()
{
    list *head = NULL;
    last = NULL;
    head = (list *)malloc(sizeof(list));

    if (head == NULL)
    {
        printf("out of memory space: \n");

        exit(0);
    }
    int n, f;
    printf("enter size: ");
    scanf("%d", &n);
    printf("enter factor: ");
    scanf("%d", &f);

    createlist(head, n);

    del_gpterm_nodes(head, n, f);

    TraverseList(head, f, n);

    return 0;
}

void createlist(list *node, int n)
{
    printf("\n creation of a linked list \n\n");

    printf("the fibonacci numbers in the list are: \n");

    int i = 1;
    int j = 1;
    int k = 1;
    int m = 1;

    node->data = j;
    printf(" %d ", node->data);

    node->backward = NULL;

    node->forward = NULL;

    last = node;

    while (i <= n)
    {
        list *p = NULL;

        p = (list *)malloc(sizeof(list));

        if (p == NULL)
        {
            printf("out of memory space: \n");
            exit(0);
        }

        node->forward = p;
        node = p;
        node->data = m;
        printf(" %d ", node->data);

        node->backward = last;
        node->forward = NULL;
        last = p;

        i = i + 1;
        m = j + k;
        j = k;
        k = m;
    }
    printf("\n");
}
void del_gpterm_nodes(list *head, int n, int f)
{
    list *node = head;

    int y = 2, v = 1;
    if (f == 2)
    {
        node = node->forward;
        for (int i = 0; i < n - 2; i = i + 1)
        {
            node = node->forward;

            if (i + 3 == pow(2, y))
            {
                if (i == n - 3)
                {
                    node->backward->forward = NULL;
                }
                else
                {
                    node->backward->forward = node->forward;

                    node->forward->backward = node->backward;
                }
                v = v + 1;
            }
        }
    }
}
void TraverseList(list *head, int f, int n)
{
    if (n == 1 || (n == 2 && f == 2))
    {
        printf("\n there are no nodes left in the list\n");
    }
    else
    {
        head = head->forward;
        head->backward = NULL;
        if (f == 2)
        {
            head = head->forward;
            head->backward = NULL;

            printf("\n the values after deleting nodes in the List are: \n");

            list *node = head;
            while (node != NULL)
            {
                printf("%d", node->data);
                node = node->forward;
            }
            printf("\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
typedef node
{
    long long fibo;
    node *prev;
    node *next;
}
node;
node *createlist(node *head, unsigned int n);
void printfromstart(char *str, node *head);
void printfromend(char *str, node *tail);
void del_gpterm(node **head_pointer, node **tail_pointer, int factor, unsigned int n);
int main()
{
    unsigned int n, gpfactor;
    printf("enter the number of nodes:-\t");
    scanf("%d", &n);
    printf("enter the factor of gp series:-\t");
    scanf("%d", &gpfactor);
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        printf("no memory allocated");
        exit(0);
    }
    node *tail = createlist(head, n);
    printfromstart("\ncreatedlist(accessing from head):", head);
    printfromend("\ncreatedlist(accessing from tail):", tail);
    del_gpterm(&head, &tail, gpfactor, n);
    printfromstart("\ncreatedlist(accessing from head):", head);
    printfromend("\ncreatedlist(accessing from tail):", tail);
    printf("\n");
    tail = NULL;
}
node *createlist(node *head, unsigned int n)
{
    if (n > 0)
    {
        node *tail;
        head->fibo = 1;
        head->prev = NULL;
        head->next = NULL;
        node *previous = head;
        if (n > 1)
        {
            node *pre_previous = NULL;
            node *temp = (node *)malloc(sizeof(node));
            if (temp == NULL)
            {
                printf("no memory allocated");
                exit(0);
            }
            head->next = temp;
            head = temp;
            head->fibo = 1;
            head->prev = previous;
            head->next = NULL;
            pre_previous = previous;
            previous = head;
            for (int i = 0; i < (n - 2); ++i)
            {
                node *temp = (node *)malloc(sizeof(node));
                if (temp == NULL)
                {
                    printf("no memory allocated");
                    exit(0);
                }
                head->next = temp;
                head = temp;
                head->fibo = previous->fibo + pre_previous->fibo;
                head->prev = previous;
                head->next = NULL;
                pre_previous = previous;
                previous = head;
            }
        }
        tail = previous;
        return tail;
    }
}

void printfromstart(char *str, node *head)
{
    printf("%s", str);
    while (head != NULL)
    {
        printf(" %lld ", head->fibo);
        head = head->next;
    }
}
void printfromend(char *str, node *tail)
{
    printf("%s", str);
    while (tail != NULL)
    {
        printf(" %lld ", tail->fibo);
        tail = tail->prev;
    }
}

void del_gpterm(node **head_pointer, node **tail_pointer, int factor, unsigned int n)
{
    node *flag = *head_pointer;
    node *previous = NULL;
    int del_index = 1;
    int i = 1;
    for (i = 1; i <= n; i++)
    {
        if (flag->next == NULL)
        {
            if (i == del_index)
            {
                node *temp = previous->next;
                previous->next = NULL;
                *tail_pointer = previous;
                free(temp);
            }
        }
        else if (flag->prev == NULL)
        {
            if (i == del_index)
            {
                del_index = del_index * factor;
                *head_pointer = flag->next;
                flag->next->prev = NULL;
                free(flag);
                flag = *head_pointer;
            }
            else
            {
                previous = flag;
                flag = flag->next;
            }
        }
        else
        {
            if (i == del_index)
            {
                del_index = del_index * factor;
                node *temp = flag;
                previous->next = previous->next->next;
                flag = flag->next;
                flag->prev = previous;
                free(temp);
            }
            else
            {
                previous = flag;
                flag = flag->next;
            }
        }
    }
}

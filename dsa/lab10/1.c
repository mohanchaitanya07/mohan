#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 8
typedef struct qnode
{
    int number;
    struct qnode *next;

} queue;
typedef struct lnode
{
    int number;
    struct lnode *next;
} list_node;

queue *front = NULL;
queue *rear = NULL;
void enqueue(int a);
int dequeue();
int check_empty();
void bfsmatrix(int adjmatrix[][MAX], int start, int n);
void dfsmatrix(int adjmatrix[][MAX], int start, int n);
void topomatrix(int adjmatrix[][MAX], int n);

void c_adlist(int adjmatrix[][MAX], list_node **adj_list);
void bfslist(list_node **adj_list, int start, int n);
void dfslist(list_node **adj_list, int start, int n);
void topolist(list_node **adj_list, int n);
int main()
{
    int adjmatrix[MAX][MAX] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}};

    list_node **adj_list = (list_node **)calloc(MAX, sizeof(list_node *));
    fprintf(stdout, "Adjacency matrix\n");
    bfsmatrix(adjmatrix, 1, MAX);
    fprintf(stdout, "\n\tDF_Search: ");
    dfsmatrix(adjmatrix, 1, MAX);
    topomatrix(adjmatrix, MAX);
    fprintf(stdout, "\n\n");

    fprintf(stdout, "Adjacency list\n");
    c_adlist(adjmatrix, adj_list);
    bfslist(adj_list, 1, MAX);
    fprintf(stdout, "\n\tDF_Search: ");
    dfslist(adj_list, 1, MAX);
    topolist(adj_list, MAX);
    fprintf(stdout, "\n");
}

void c_adlist(int adjmatrix[][MAX], list_node **adj_list)
{
    for (int i = 1; i < MAX; i++)
    {
        list_node *rear = NULL;
        for (int j = 1; j < MAX; j++)
        {
            if (adjmatrix[i][j] == 1)
            {
                if (adj_list[i] == NULL)
                {
                    list_node *tmp = (list_node *)malloc(sizeof(list_node));
                    tmp->number = j;
                    tmp->next = NULL;
                    adj_list[i] = tmp;
                    rear = tmp;
                }
                else
                {
                    list_node *tmp = (list_node *)malloc(sizeof(list_node));
                    tmp->number = j;
                    tmp->next = NULL;
                    rear->next = tmp;
                    rear = tmp;
                }
            }
        }
    }
}
void bfslist(list_node **adj_list, int start, int n)
{
    fprintf(stdout, "\tBF_Search: ");
    int i = start;
    int visited[MAX] = {0};
    fprintf(stdout, " %d", i);
    enqueue(i);
    while (!check_empty())
    {
        i = dequeue();

        list_node *head = adj_list[i];
        for (head; head != NULL; head = head->next)
        {
            if (visited[head->number] == 0)
            {
                printf(" %d", head->number);
                visited[head->number] = 1;
                enqueue(head->number);
            }
        }
    }
}
void dfslist(list_node **adj_list, int start, int n)
{
    static int visited[MAX] = {0};
    if (visited[start] == 0)
    {
        fprintf(stdout, " %d", start);
        visited[start] = 1;
        list_node *head = adj_list[start];
        for (head; head != NULL; head = head->next)
        {
            if (visited[head->number] == 0)
            {
                dfslist(adj_list, head->number, n);
            }
        }
    }
}
void topolist(list_node **adj_list, int n)
{

    int indeg[MAX] = {0};
    int visited[MAX] = {0};
    int count = 1, count2 = 1;
    int times = 0;
    int topolist[MAX];
    while (count2 < n)
    {
        for (int i = 1; i < n; i++)
            for (list_node *j = adj_list[i]; j != NULL; j = j->next)
                if (j->number == count2)
                {
                    indeg[count2] = indeg[count2] + 1;
                    break;
                }
        count2++;
    }
    printf("\ntopological order:");
    count2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            enqueue(i);
        }
    }
    while (count2 < 7)
    {
        while (!check_empty())
        {
            int i = dequeue();
            topolist[++count2] = i;

            for (list_node *j = adj_list[i]; j != NULL; j = j->next)
            {
                indeg[j->number]--;
            }

            visited[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (indeg[i] == 0 && visited[i] == 0)
            {
                enqueue(i);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        printf(" %d", topolist[i]);
    }
}
void bfsmatrix(int adjmatrix[][MAX], int start, int n)
{
    fprintf(stdout, "\tBF_Search: ");
    int i = start;
    int visited[MAX] = {0};
    fprintf(stdout, " %d", i);
    enqueue(i);
    while (!check_empty())
    {
        i = dequeue();
        for (int j = 1; j < n; j++)
        {
            if (adjmatrix[i][j] == 1 && visited[j] == 0)
            {
                printf(" %d", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
void dfsmatrix(int adjmatrix[][MAX], int start, int n)
{
    static int visited[8] = {0};
    if (visited[start] == 0)
    {
        fprintf(stdout, " %d", start);
        visited[start] = 1;
        for (int j = 1; j < n; j++)
        {
            if (adjmatrix[start][j] == 1 && visited[j] == 0)
            {
                dfsmatrix(adjmatrix, j, n);
            }
        }
    }
}
void topomatrix(int adjmatrix[][8], int n)
{

    int indeg[8] = {0};
    int visited[8] = {0};
    int count = 1, count2 = 1;
    int times = 0;
    int topolist[8];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            indeg[i] = indeg[i] + adjmatrix[j][i];

    printf("\ntopological order:");
    front = NULL;
    for (int i = 1; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            enqueue(i);
        }
    }
    while (count < n)
    {
        while (!check_empty())
        {
            int i = dequeue();
            topolist[count++] = i;

            for (int j = 1; j < n; j++)
            {
                if (adjmatrix[i][j] == 1)
                    indeg[j]--;
            }

            visited[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (indeg[i] == 0 && visited[i] == 0)
            {
                enqueue(i);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        printf(" %d", topolist[i]);
    }
}
void enqueue(int a)
{
    if (check_empty())
    {
        queue *tmp = (queue *)malloc(sizeof(queue));
        tmp->number = a;
        tmp->next = NULL;
        front = tmp;
        rear = tmp;
        return;
    }
    queue *tmp = (queue *)malloc(sizeof(queue));
    tmp->number = a;
    tmp->next = NULL;
    rear->next = tmp;
    rear = tmp;
}
int dequeue()
{
    if (check_empty())
    {
        printf("Queue is empty\n");
        exit(0);
    }
    queue *tmp = front;
    int result = front->number;
    front = front->next;
    free(tmp);
    return result;
}
int check_empty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}
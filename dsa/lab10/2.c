#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
typedef struct lnode
{
    int number;
    int weight;
    int isvisited;
    struct lnode *next;
} list_node;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};
struct subset
{
    int parent;
    int rank;
};
struct Graph *createGraph(int V, int E);
void p_mst(int V, int adj_max[V][V]);
int printfn_mst(int parent[], int V, int adj_max[V][V]);
int m_key(int key[], int V, bool mstSet[]);
void createfn(int N, int adj_mat[][N]);
int cal(int V, int adj_mat[][V]);
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int myComp(const void *a, const void *b);
void KruskalMST(struct Graph *graph);
int main()
{
    int V;
    printf("Enter the number of nodes: ");
    scanf("%d", &V);
    int adj_mat[V][V], E;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj_mat[i][j] = 0;

    createfn(V, adj_mat);
    E = cal(V, adj_mat);
    struct Graph *graph = createGraph(V, E);
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (adj_mat[i][j] != 0)
            {
                graph->edge[count].src = j;
                graph->edge[count].dest = i;
                graph->edge[count++].weight = adj_mat[i][j];
            }
        }
    }
    printf("\nPRIM'S ALGORITHM\n");
    p_mst(V, adj_mat);
    printf("\n\nKRUSKAL'S ALGORITHM\n");
    KruskalMST(graph);
}
int cal(int V, int adj_mat[][V])
{
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < i; j++)
        {
            count++;
        }
    }
    return count;
}
int m_key(int key[], int V, bool mstSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int printfn_mst(int parent[], int V, int adj_max[V][V])
{
    int minimumcost = 0;
    printf("Edge\t\tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%-3d - %-3d \t%d \n", parent[i], i, adj_max[i][parent[i]]);
        minimumcost += adj_max[i][parent[i]];
    }
    printf("\tMinimum Cost Spanning tree : %d", minimumcost);
}

void p_mst(int V, int adj_max[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = m_key(key, V, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (adj_max[u][v] && mstSet[v] == false && adj_max[u][v] < key[v])
                parent[v] = u, key[v] = adj_max[u][v];
    }

    printfn_mst(parent, V, adj_max);
}

void createfn(int N, int adj_mat[][N])
{
    srand((unsigned)time(NULL));
    for (int i = N - 1; i >= 0; i--)
    {

        for (int j = i - 1; j >= 0; j--)
        {
            if (i == j)
            {
                continue;
            }
            int rnd = rand() % 2;
            if (rnd)
            {
                adj_mat[i][j] = (rand() % 20) + 2;
                adj_mat[j][i] = adj_mat[i][j];
            }
        }
    }
}

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)(malloc(sizeof(struct Graph)));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge *)malloc(sizeof(struct Edge) * E);

    return graph;
}

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge
        result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
          myComp);

    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {

        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf(
        "Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        printf("%-2d -- %2d  ==  %2d\n", result[i].src,
               result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("\tMinimum Cost Spanning tree : %d", minimumCost);
    return;
}
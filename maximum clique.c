#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int n, k, maxClique[MAX_VERTICES], currClique[MAX_VERTICES];

void printClique()
{
    int i;
    printf("Maximum clique: ");
    for (i = 0; i < k; i++)
        {
        printf("%d ", maxClique[i]);
    }
    printf("\n");
}

int isClique(int currClique[], int len)
{
    int i, j;
    for (i = 0; i < len; i++)
        {
        for (j = i+1; j < len; j++)
        {
            if (graph[currClique[i]][currClique[j]] == 0)
             {
                return 0;
            }
        }
    }
    return 1;
}

void branchAndBound(int currVertex, int currCliqueSize)
 {
    int i;
    if (currVertex > n)
        {
        if (currCliqueSize > k)
        {
            memcpy(maxClique, currClique, sizeof(int)*currCliqueSize);
            k = currCliqueSize;
            printClique();
        }
    } else
     {
        currClique[currCliqueSize] = currVertex;
        if (isClique(currClique, currCliqueSize+1))
         {
            branchAndBound(currVertex+1, currCliqueSize+1);
        }
        if (n - currVertex + 1 + currCliqueSize > k)
        {
            branchAndBound(currVertex+1, currCliqueSize);
        }
    }
}

int main()
{
    int i, j, m, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges:\n");
    for (i = 0; i < m; i++)
        {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    k = 0;
    branchAndBound(1, 0);
    printf("Size of maximum clique is %d\n", k);
    return 0;
}


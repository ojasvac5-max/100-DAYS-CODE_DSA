#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

int adj[MAXN][MAXN];
int adjSize[MAXN];     
int visited[MAXN];

void dfs(int u, int n, int** edges, int* adjSize, int** adjList) {
    visited[u] = 1;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adjList[u][i];
        if (!visited[v]) {
            dfs(v, n, edges, adjSize, adjList);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int** adjList = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--; 
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }

    dfs(0, n, NULL, adjSize, adjList);

    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
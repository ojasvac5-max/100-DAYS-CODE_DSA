#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1000

int graph[MAXN][MAXN];
int key[MAXN];
int mstSet[MAXN];

int minKey(int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int n) {
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(n);
        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; 
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int result = primMST(n);
    printf("%d\n", result);

    return 0;
}
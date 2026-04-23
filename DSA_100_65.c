#include <stdio.h>

#define SIZE 100

int adj[SIZE][SIZE];
int visited[SIZE];
int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i]) { 
            
            if(!visited[i]) {
                if(dfs(i, node, n)) return 1;
            }
            else if(i != parent) {
                return 1; 
            }
        }
    }
    return 0;
}

int hasCycle(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, n)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    if(hasCycle(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
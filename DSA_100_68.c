#include <stdio.h>

#define SIZE 100

int adj[SIZE][SIZE];
int indegree[SIZE];
int queue[SIZE];
int front = 0, rear = 0;

void push(int x) {
    queue[rear++] = x;
}

int pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void topoSort(int n) {
    
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j]) {
                indegree[j]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            push(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    while(!isEmpty()) {
        int node = pop();
        printf("%d ", node);
        count++;

        for(int i = 0; i < n; i++) {
            if(adj[node][i]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    push(i);
                }
            }
        }
    }

    printf("\n");
    if(count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter directed edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort(n);

    return 0;
}
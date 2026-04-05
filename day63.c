#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // input edges until -1 -1
    while (1) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1)
            break;

        addEdge(u, v);
    }

    int start;
    scanf("%d", &start);

    DFS(start);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (DIRECTED)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS for topo sort
void topoDFS(int v) {

    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            topoDFS(adjVertex);
        }

        temp = temp->next;
    }

    push(v); // push after visiting children
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

    // run DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoDFS(i);
        }
    }

    // print stack (reverse order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
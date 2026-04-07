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
int recStack[MAX];

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

// DFS cycle detection
int hasCycle(int v) {

    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            if (hasCycle(adjVertex))
                return 1;
        }
        else if (recStack[adjVertex]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0; // backtrack
    return 0;
}

int main() {

    int n;
    scanf("%d", &n);

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    // input edges until -1 -1
    while (1) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1)
            break;

        addEdge(u, v);
    }

    int cycle = 0;

    // handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
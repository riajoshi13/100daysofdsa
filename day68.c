#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];
int queue[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add directed edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    indegree[v]++;
}

int main() {

    int n;
    scanf("%d", &n);

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    // input edges
    while (1) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1)
            break;

        addEdge(u, v);
    }

    int front = 0, rear = 0;

    // push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    // BFS
    while (front < rear) {

        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];

        while (temp != NULL) {
            int adjVertex = temp->vertex;

            indegree[adjVertex]--;

            if (indegree[adjVertex] == 0) {
                queue[rear++] = adjVertex;
            }

            temp = temp->next;
        }
    }

    // cycle check
    if (count != n) {
        printf("\nCycle exists (Not a DAG)");
    }

    return 0;
}
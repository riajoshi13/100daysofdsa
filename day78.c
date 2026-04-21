#include <stdio.h>

#define MAX 100
#define INF 99999

int minKey(int key[], int mstSet[], int n) {
    int min = INF, minIndex;

    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // input edges (convert to 0-based)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0; // start from node 0

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {

        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d", totalWeight);

    return 0;
}
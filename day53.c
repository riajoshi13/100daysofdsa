#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure
struct QNode {
    struct Node* node;
    int hd;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {

            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Vertical Order
void verticalOrder(struct Node* root) {

    if (root == NULL)
        return;

    struct QNode queue[100];
    int front = 0, rear = 0;

    int map[200][100]; // store nodes by HD
    int count[200] = {0};

    int offset = 100; // handle negative index

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {

        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // print vertical order
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0) return 0;

    int value;

    // Create head node
    scanf("%d", &value);
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;

    struct Node* temp = head;

    // Insert remaining nodes
    for(int i = 1; i < n; i++) {
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    // Traverse and print
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
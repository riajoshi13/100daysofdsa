#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Forward Traversal
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    // Case 1: If head contains key
    if(head != NULL && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while(current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If key found
    if(current != NULL) {
        prev->next = current->next;
        free(current);
    }

    return head;
}

// Print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createList(n);

    int key;
    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}
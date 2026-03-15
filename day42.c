#include <stdio.h>

#define MAX 100

int queue[MAX], stack[MAX];
int front = 0, rear = -1, top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {

    int n, x;

    scanf("%d", &n);

    // enqueue elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // move queue → stack
    while(front <= rear) {
        push(dequeue());
    }

    // move stack → queue
    front = 0;
    rear = -1;

    while(top != -1) {
        enqueue(pop());
    }

    // display reversed queue
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
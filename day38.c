#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

void push_front(int x) {

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        printf("Overflow\n");
    }
    else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        printf("Overflow\n");
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {

    if (isEmpty()) {
        printf("Deque Empty\n");
        return;
    }

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {

    if (isEmpty()) {
        printf("Deque Empty\n");
        return;
    }

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void display() {

    if (isEmpty())
        return;

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    pop_back();

    display();

    return 0;
}
#include <stdio.h>
#include <string.h>

#define SIZE 100

int hashTable[SIZE];

// Initialize table
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {

    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if (hashTable[index] == -1) {
            hashTable[index] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key, int m) {

    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if (hashTable[index] == key)
            return 1;

        if (hashTable[index] == -1)
            return 0;
    }

    return 0;
}

int main() {

    int m, n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // operations

    init();

    for (int i = 0; i < n; i++) {

        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        }
        else if (strcmp(op, "SEARCH") == 0) {

            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
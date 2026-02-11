#include <stdio.h>

int main() {
    int p, q;

    // Read size of first log
    scanf("%d", &p);
    int arr1[p];

    // Read elements of first log
    for (int i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int arr2[q];

    // Read elements of second log
    for (int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    int i = 0, j = 0;

    // Merge process
    while (i < p && j < q) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
        } else {
            printf("%d ", arr2[j]);
            j++;
        }
    }

    // Print remaining elements of arr1
    while (i < p)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float arr[100];
    int size;
} Bucket;

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    float arr[100];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    Bucket buckets[100];

    for (int i = 0; i < n; i++)
        buckets[i].size = 0;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        buckets[index].arr[buckets[index].size++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++)
        insertionSort(buckets[i].arr, buckets[i].size);

    // Concatenate buckets
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[k++] = buckets[i].arr[j];
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
#include <stdio.h>

// Check Min Heap
int isMinHeap(int arr[], int n) {

    for (int i = 0; i <= (n - 2) / 2; i++) {

        // left child
        int left = 2*i + 1;
        // right child
        int right = 2*i + 2;

        if (left < n && arr[i] > arr[left])
            return 0;

        if (right < n && arr[i] > arr[right])
            return 0;
    }

    return 1;
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(arr, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
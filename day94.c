#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    int arr[1000];

    int max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] > max)
            max = arr[i];
    }

    // Frequency array
    int *count = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Prefix sums
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[1000];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(count);

    return 0;
}
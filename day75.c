#include <stdio.h>

#define MAX 1000

int main() {

    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    int maxLen = 0;

    // Hash map using arrays
    int prefixSum[2 * MAX];
    int index[2 * MAX];

    for (int i = 0; i < 2 * MAX; i++)
        index[i] = -1;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        int key = sum + MAX; // shift for negative

        // If seen before
        if (index[key] != -1) {
            int len = i - index[key];
            if (len > maxLen)
                maxLen = len;
        } else {
            index[key] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}
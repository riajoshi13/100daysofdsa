#include <stdio.h>

long long merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    long long invCount = 0;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];

            // All remaining elements in left array
            // form inversions with R[j]
            invCount += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return invCount;
}

long long mergeSort(int arr[], int left, int right) {

    long long invCount = 0;

    if (left < right) {

        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);

        invCount += merge(arr, left, mid, right);
    }

    return invCount;
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long inversions = mergeSort(arr, 0, n - 1);

    printf("%lld", inversions);

    return 0;
}
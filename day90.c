#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {

    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {

        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        }
        else {
            painters++;
            currentTime = boards[i];

            if (painters > k)
                return 0;
        }
    }

    return 1;
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    int boards[1000];

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);

        if (boards[i] > low)
            low = boards[i];

        high += boards[i];
    }

    int answer = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    printf("%d", answer);

    return 0;
}
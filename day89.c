#include <stdio.h>

int isPossible(int books[], int n, int m, int maxPages) {

    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {

        if (pagesSum + books[i] <= maxPages) {
            pagesSum += books[i];
        }
        else {
            students++;
            pagesSum = books[i];

            if (students > m)
                return 0;
        }
    }

    return 1;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int books[1000];

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);

        if (books[i] > low)
            low = books[i];

        high += books[i];
    }

    int answer = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid)) {
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
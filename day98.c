#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

int main() {

    int n;
    scanf("%d", &n);

    Interval arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), compare);

    int currentStart = arr[0].start;
    int currentEnd = arr[0].end;

    for (int i = 1; i < n; i++) {

        if (arr[i].start <= currentEnd) {

            if (arr[i].end > currentEnd)
                currentEnd = arr[i].end;
        }
        else {

            printf("%d %d\n", currentStart, currentEnd);

            currentStart = arr[i].start;
            currentEnd = arr[i].end;
        }
    }

    printf("%d %d\n", currentStart, currentEnd);

    return 0;
}
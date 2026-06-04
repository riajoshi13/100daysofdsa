#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position; // Descending order
}

int main() {
    int target, n;

    scanf("%d", &target);
    scanf("%d", &n);

    Car cars[1000];

    // Input positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    // Input speeds
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < n; i++) {

        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}
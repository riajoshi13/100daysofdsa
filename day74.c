#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {

    int n;
    scanf("%d", &n);

    char names[MAX][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char unique[MAX][50];
    int count[MAX] = {0};
    int size = 0;

    // Count frequency
    for (int i = 0; i < n; i++) {

        int found = 0;

        for (int j = 0; j < size; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(unique[size], names[i]);
            count[size] = 1;
            size++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < size; i++) {

        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}
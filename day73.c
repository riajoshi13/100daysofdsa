#include <stdio.h>
#include <string.h>

int main() {

    char str[1000];
    scanf("%s", str);

    int freq[26] = {0};

    // Step 1: count frequency
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    // Step 2: find first non-repeating
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[str[i] - 'a'] == 1) {
            printf("%c", str[i]);
            return 0;
        }
    }

    // if none found
    printf("$");

    return 0;
}
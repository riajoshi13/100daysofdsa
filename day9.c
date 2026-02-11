#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    // Input string
    scanf("%s", str);

    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Reverse using two pointers
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    // Output reversed string
    printf("%s", str);

    return 0;
}

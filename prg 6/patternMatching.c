#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char text[100], pattern[20];
    int i, j, found = 0;

    printf("Enter text: ");
    gets(text);
    printf("Enter pattern to search: ");
    gets(pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at position %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Pattern not found\n");
}

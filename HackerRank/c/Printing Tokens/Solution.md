#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    
    // Read the entire line until a newline is encountered
    if (scanf("%[^\n]s", s) != 1) return 0;
    
    // Reallocate memory to fit the actual string length
    s = realloc(s, strlen(s) + 1);

    // Iterate through the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            printf("\n");
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n"); // Ensure the last word is followed by a newline

    free(s);
    return 0;
}

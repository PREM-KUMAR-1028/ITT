#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    
    // Read the string
    if (scanf("%s", s) != 1) return 0;

    // Initialize frequency array for digits 0-9 with zeros
    int counts[10] = {0};

    // Iterate through the string character by character
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the character is a digit
        if (s[i] >= '0' && s[i] <= '9') {
            // Convert char to int (e.g., '5' - '0' = 5) and increment
            counts[s[i] - '0']++;
        }
    }

    // Print the frequencies separated by spaces
    for (int i = 0; i < 10; i++) {
        printf("%d ", counts[i]);
    }
    printf("\n");

    free(s);
    return 0;
}

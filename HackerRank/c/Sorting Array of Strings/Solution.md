#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int distinct_chars_count(const char *s) {
    int count = 0;
    int alphabet[26] = {0};
    while (*s) {
        if (alphabet[*s - 'a'] == 0) {
            alphabet[*s - 'a'] = 1;
            count++;
        }
        s++;
    }
    return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int res = distinct_chars_count(a) - distinct_chars_count(b);
    return (res == 0) ? strcmp(a, b) : res;
}

int sort_by_length(const char* a, const char* b) {
    int res = strlen(a) - strlen(b);
    return (res == 0) ? strcmp(a, b) : res;
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

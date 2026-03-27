#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // The size of the grid is always (2*n - 1)
    int size = 2 * n - 1;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Find the distance to the closest edge
            int min_dist = i < j ? i : j;
            min_dist = min_dist < size - i ? min_dist : size - i - 1;
            min_dist = min_dist < size - j ? min_dist : size - j - 1;
            
            // The value is n minus the distance from the outermost layer
            printf("%d ", n - min_dist);
        }
        printf("\n");
    }
    return 0;
}

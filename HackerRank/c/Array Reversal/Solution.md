#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    if (scanf("%d", &num) != 1) return 0;
    
    arr = (int*) malloc(num * sizeof(int));
    if (arr == NULL) return 1; // Memory allocation safety

    for(i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    /* Logic to reverse the array in-place */
    for (i = 0; i < num / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[num - i - 1];
        arr[num - i - 1] = temp;
    }

    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);
    
    free(arr);
    return 0;
}

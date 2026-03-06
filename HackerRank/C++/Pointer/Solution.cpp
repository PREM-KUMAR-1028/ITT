#include <stdio.h>
#include <cstdlib> 
void update(int *a, int *b) 
{
    int old_a = *a;
    int old_b = *b;
    *a = old_a + old_b;
    *b = abs(old_a - old_b);
}
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    if (scanf("%d %d", &a, &b) == 2)
    {
        update(pa, pb);
        printf("%d\n%d", a, b);
    }
    return 0;
}

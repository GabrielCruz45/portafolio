#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int *a = malloc(sizeof(int) * 10); // Dynamically Allocated Array, we can tret it as an array

    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);

    int *a = calloc(size, sizeof(int)); // calloc zeroes de space first (it's considerably slower!!!)
    if (a == NULL)
    {
        printf("Memory could not be allocated.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) a[i] = size - i;

    for (int i = 0; i < size; i++)
        printf("a[%d] = %d\n", i, *(a + i));
    printf("\n");

    printf("%p\n", a);

    a = realloc(a,  sizeof(int) * (size + 5));

    for (int i = size; i < size + 5; i++) a[i] = 9;

    for (int i = 0; i < size + 5; i++)
        printf("a[%d] = %d\n", i, *(a + i));
    printf("\n");

    free(a);
    return 0;
}
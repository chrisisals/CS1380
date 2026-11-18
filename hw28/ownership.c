#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *data = malloc(sizeof(int));

    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    *data = 42;

    printf("Value: %d\n", *data);

    free(data);
    data = NULL;

    if (data == NULL) {
        printf("Pointer safely set to NULL\n");
    }

    return 0;
}

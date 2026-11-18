#include "secure.h"
#include <stdio.h>

int main(void)
{
    char buffer[10];

    int result = safe_copy(NULL, 10, "Hello");
    printf("Invalid copy result: %d\n", result);

    result = safe_concat(buffer, 0, "Hello");
    printf("Invalid concat result: %d\n", result);

    return 0;
}


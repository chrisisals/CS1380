#include "secure.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[10];

    assert(safe_copy(buffer, sizeof(buffer), "Hello") == 0);
    assert(strcmp(buffer, "Hello") == 0);

    assert(safe_copy(buffer, sizeof(buffer), "Hello World") == 1);
    assert(strcmp(buffer, "Hello Wor") == 0);

    assert(safe_copy(buffer, sizeof(buffer), "Hi")==0);
    assert(safe_concat(buffer, sizeof(buffer), " there!") == 0);
    assert(strcmp(buffer, "Hi there!") == 0);

    assert(safe_copy(NULL, 10, "Hello") == -1);
    assert(safe_concat(buffer, 0, "Hello") == -1);

    printf("All regression tests passed!\n");

    return 0;
}

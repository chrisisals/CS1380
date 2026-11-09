#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("out.txt", "w");

    if (file == NULL) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    if (fprintf(file, "Hello, CS 1380!\n") < 0 ||
        fprintf(file, "Learning file I/O in C.\n") < 0) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fclose(file) == EOF) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    file = fopen("out.txt", "r");

    if (file == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    char line[100];

    while (fgets(line, sizeof line, file) != NULL) {
        printf("%s", line);
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fclose(file) == EOF) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

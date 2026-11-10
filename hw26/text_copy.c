#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *input = fopen("input.txt", "r");

    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output = fopen("copy.txt", "w");

    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    char line[256];
    int count = 0;

    while (fgets(line, sizeof line, input) != NULL) {
        if (fputs(line, output) == EOF) {
            perror("Error writing output file");
            fclose(input);
            fclose(output);
            return EXIT_FAILURE;
        }

        count++;
    }

    if (ferror(input)) {
        perror("Error reading input file");
        fclose(input);
        fclose(output);
        return EXIT_FAILURE;
    }

    if (fclose(input) == EOF) {
        perror("Error closing input file");
        fclose(output);
        return EXIT_FAILURE;
    }

    if (fclose(output) == EOF) {
        perror("Error closing output file");
        return EXIT_FAILURE;
    }

    printf("Lines copied: %d\n", count);

    return EXIT_SUCCESS;
}

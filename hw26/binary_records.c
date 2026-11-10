#include <stdio.h>
#include <stdlib.h>

struct Record {
    int id;
    int score;
};

int main(void)
{
    struct Record records[] = {
        {1, 95},
        {2, 87},
        {3, 92},
        {4, 78}
    };

    size_t count = sizeof records / sizeof records[0];

    FILE *file = fopen("records.bin", "wb");

    if (file == NULL) {
        perror("Error opening binary file for writing");
        return EXIT_FAILURE;
    }

    size_t written = fwrite(records, sizeof records[0], count, file);

    if (written != count) {
        perror("Error writing binary records");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fclose(file) == EOF) {
        perror("Error closing binary file");
        return EXIT_FAILURE;
    }

    struct Record loaded[4];

    file = fopen("records.bin", "rb");

    if (file == NULL) {
        perror("Error opening binary file for reading");
        return EXIT_FAILURE;
    }

    size_t read_count = fread(loaded, sizeof loaded[0], count, file);

    if (read_count != count) {
        fprintf(stderr, "Error: Expected %zu records, read %zu\n",
                count, read_count);
        fclose(file);
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < read_count; i++) {
        printf("ID: %d, Score: %d\n",
               loaded[i].id, loaded[i].score);
    }

    if (fclose(file) == EOF) {
        perror("Error closing binary file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

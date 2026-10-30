
/*
 * File: main.c
 * Author: Christopher Luckey
 * Description: Demonstrates the lineup label helper functions.
 */

#include <stdio.h>
#include "lineup.h"

int main(void)
{
    char team[] = "Wolves";
    char copied[50];
    char joined[50];

    /* Print the original team and its length. */
    print_label(team);
    printf("Wolves len=%d\n", label_len(team));

    /* Demonstrate safe_copy. */
    safe_copy(copied, 50, team);
    printf("copy: ");
    print_label(copied);

    /* Demonstrate safe_join. */
    safe_copy(joined, 50, team);
    safe_join(joined, 50, "-A");
    printf("join: ");
    print_label(joined);

    /* Demonstrate labels_match. */
    printf("match same -> %d\n",
           labels_match("Wolves", "Wolves"));

    printf("match different -> %d\n",
           labels_match("Wolves", "Tigers"));

    /* Demonstrate find_text. */
    printf("find olv -> %d\n",
           find_text("Wolves", "olv"));

    printf("find xyz -> %d\n",
           find_text("Wolves", "xyz"));

    /* Demonstrate NULL handling. */
    print_label(NULL);
    printf("NULL length -> %d\n", label_len(NULL));

    return 0;
}


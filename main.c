/*
HEAD
 * Demonstrates printing, searching and updating a console picture.
 * Name: Christopher Luckey 
 */

#include "picture.h"
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int pic[][COLS] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int nrows = (int)(sizeof pic / sizeof pic[0]);

    printf("Original picture:\n");
    print_picture(pic, nrows);

    printf("find 1 -> %d\n", find_code(pic, nrows, 1));
    printf("find 9 -> %d\n", find_code(pic, nrows, 9));

    set_cell(pic, nrows, 2, 2, 1);
    printf("After set_cell(2, 2, 1):\n");
    print_picture(pic, nrows);

    set_cell(pic, nrows, 9, 0, 1);
    printf("set_cell(9, 0, 1) ignored\n");

    printf("Null picture test:\n");
    print_picture(NULL, 4);
    printf("find_code(NULL, 4, 1) -> %d\n", find_code(NULL, 4, 1));

    return 0;
}

 * main.c
 * Demonstrates the Player structure and helper functions.
 */

#include <stdio.h>
#include "player.h"

int main(void)
{
    struct Player player1;
    struct Player player2;

    /* Initialize two players. */
    init_player(&player1, "Alex Rivera", 7, 12);
    init_player(&player2, "Sam Ortiz", 14, 8);

    /* Print both players. */
    printf("Initial players:\n");
    print_player(&player1);
    print_player(&player2);

    /* Demonstrate get_points and add_points. */
    printf("\nPoints before: %d\n", get_points(&player1));

    add_points(&player1, 3);

    printf("Points after: %d\n", get_points(&player1));

    /* Compare jersey numbers. */
    struct Player player3;
    init_player(&player3, "Jordan Lee", 7, 20);

    printf("\nSame jersey (player1 and player3): %d\n",
           same_jersey(&player1, &player3));

    printf("Different jersey (player1 and player2): %d\n",
           same_jersey(&player1, &player2));

    /* Demonstrate NULL safety. */
    printf("\nNULL safety test:\n");

    print_player(NULL);

    printf("NULL points: %d\n", get_points(NULL));

    add_points(NULL, 5);

    printf("NULL jersey comparison: %d\n",
           same_jersey(NULL, &player1));

    /* Demonstrate an array of players. */
    struct Player roster[3];

    init_player(&roster[0], "Taylor Smith", 22, 15);
    init_player(&roster[1], "Morgan Davis", 5, 9);
    init_player(&roster[2], "Casey Brown", 11, 18);

    printf("\nTeam roster:\n");

    for (int i = 0; i < 3; i++) {
        print_player(&roster[i]);
    }

    return 0;
}

 848baba (Add player demo and homework answers)

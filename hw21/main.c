#include "roster.h"
#include <stdio.h>

int main(void)
{
    char team1[] = "Tigers";
    char team2[] = "Tigers";
    char team3[] = "Eagles";
    char copied[20];

    printf("Team name: ");
    print_team(team1);
    printf("\n");

    printf("Length: %zu\n", team_len(team1));

    team_copy(copied, sizeof(copied), team1);
    printf("Copied name: %s\n", copied);

    printf("Team 1 and Team 2 same: %s\n",
           team_same(team1, team2) ? "yes" : "no");

    printf("Team 1 and Team 3 same: %s\n",
           team_same(team1, team3) ? "yes" : "no");

    shout(team1);
    printf("Shouted name: %s\n", team1);

    return 0;
}

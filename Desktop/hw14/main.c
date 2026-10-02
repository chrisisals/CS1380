#include <stdio.h>
#include "specials.h"

int main(void)
{
    int prices[] = {250, 350, 450};
    int order_total = sum_order(prices, 3);

    printf("order 250+350+450 = %d\n", order_total);
    printf("factorial(5) = %d\n", factorial(5));
    printf("power(2, 8) = %d\n", power(2, 8));
    printf("power(5, 0) = %d\n", power(5, 0));

    printf("add_cents via apply_op: %d\n",
           apply_op(500, 550, add_cents));

    printf("10%% of 1050 via apply_op: %d\n",
           apply_op(1050, 10, percent_off_amount));

    return 0;
}

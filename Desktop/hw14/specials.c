#include "specials.h"

int sum_order(const int prices[], int n)
{
    if (n <= 0) {
        return 0;
    }

    return prices[0] + sum_order(prices + 1, n - 1);
}

int factorial(int n)
{
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int power(int base, int exp)
{
    if (exp == 0) {
        return 1;
    }

    return base * power(base, exp - 1);
}

int add_cents(int a, int b)
{
    return a + b;
}

int percent_off_amount(int price_cents, int percent)
{
    return (price_cents * percent) / 100;
}

int apply_op(int a, int b, price_op op)
{
    return op(a, b);
}

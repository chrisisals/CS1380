#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/* Preconditions: n >= 0 */
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

/* Preconditions: n >= 0 */
long long fib(int n) {
    if (n < 2) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

/* WHY: Recursion reduces the array until one element remains. */
int max_in_array(const int *a, size_t n) {
    if (a == NULL || n == 0) {
        return 0;
    }

    if (n == 1) {
        return a[0];
    }

    int max_rest = max_in_array(a + 1, n - 1);

    if (a[0] > max_rest) {
        return a[0];
    }

    return max_rest;
}

bool is_palindrome(const char *s, size_t i, size_t j) {
    if (s == NULL) {
        return false;
    }

    if (i >= j) {
        return true;
    }

    if (s[i] != s[j]) {
        return false;
    }

    return is_palindrome(s, i + 1, j - 1);
}

int main(void) {
    int numbers[] = {4, 9, 2, 15, 7};
    const char *word = "racecar";

    printf("factorial(0) = %lld\n", factorial(0));
    printf("factorial(5) = %lld\n", factorial(5));
    printf("fib(0) = %lld\n", fib(0));
    printf("fib(10) = %lld\n", fib(10));

    printf("Maximum array value = %d\n",
           max_in_array(numbers, 5));

    printf("racecar palindrome = %s\n",
           is_palindrome(word, 0, strlen(word) - 1)
               ? "true" : "false");

    return 0;
}

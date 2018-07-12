/*
    Given an integer n, return the number of trailing zeroes in n!.

    Note: Your solution should be in logarithmic time complexity.

    Example :

    n = 5
    n! = 120
    Number of trailing zeros = 1
    So, return 1
*/

int Solution::trailingZeroes(int A) {
    if (A < 5)
        return 0;

    int count = 0, divisor = 5;
    while (A / divisor > 0)
    {
        count += A/divisor;
        divisor *= 5;
    }

    return count;
}

/*
    Reverse digits of an integer.

    Example1:

    x = 123,

    return 321
    Example2:

    x = -123,

    return -321

    Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/

int Solution::reverse(int A) {
    if (A == 0)
        return 0;
    int negative = 0;
    if (A < 0)
    {
        negative = 1;
        A = -A;
    }

    long int rev = 0;
    while(A > 0)
    {
        rev = rev * 10 + (A % 10);
        A /= 10;
    }

    if (negative)
    {
        rev = -rev;
        if (rev < numeric_limits<int>::min())
            return 0;
    }
    if (rev > numeric_limits<int>::max())
        return 0;

    return rev;
}

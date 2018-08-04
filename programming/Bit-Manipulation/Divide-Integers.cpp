/*
    Divide two integers without using multiplication, division and mod operator.

    Return the floor of the result of the division.

    Example:

    5 / 2 = 2
    Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
*/

int Solution::divide(int A, int B) {
    int sign = (A < 0) ^ (B < 0) ? -1 : 1;
    long long m = abs((long long)A), n = abs((long long)B);

    long long q = 0;
    for (long long t = 0, i = 31; i >= 0; --i) {
        if (t + (n << i) <= m) {
            t += (n << i);
            q |= (1ll << i);
        }
    }
    q *= sign;

    return (q > INT_MAX) || (q < INT_MIN) ? INT_MAX : q;
}

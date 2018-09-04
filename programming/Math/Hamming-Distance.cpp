/*
    Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

    For example,

    HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation of 2 (010) and 7 (111).

    Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
    Return the answer modulo 1000000007.

    Example

    Let f(x, y) be the hamming distance defined above.

    A=[2, 4, 6]

    We return,
    f(2, 2) + f(2, 4) + f(2, 6) +
    f(4, 2) + f(4, 4) + f(4, 6) +
    f(6, 2) + f(6, 4) + f(6, 6) =

    0 + 2 + 1
    2 + 0 + 1
    1 + 1 + 0 = 8
*/

int hamming (int a, int b) {
    if (a == b)
        return 0;

    int count = 0;
    for (int i = 0; i < 32; ++i)
        if ((a & 1 << i) != (b & 1 << i))
            count++;

    return count;
}

int Solution::hammingDistance(const vector<int> &A) {
    int MOD = pow(10, 9) + 7;
    long long total_dist = 0;
    for (int i = 0; i < 32; ++i) {
        long long zeros = 0, ones = 0;
        for (int j = 0; j < A.size(); ++j) {
            if (A[j] & (1 << i))
                ++ones;
            else
                ++zeros;
        }
        total_dist += 2 * ones * zeros;
        total_dist %= MOD;
    }

    return total_dist;
}

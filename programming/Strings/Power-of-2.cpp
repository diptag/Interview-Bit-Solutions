/*
    Find if Given number is power of 2 or not.
    More specifically, find if given number can be expressed as 2^k where k >= 1.

    Input:

    number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
    Output:

    return 1 if the number is a power of 2 else return 0

    Example:

    Input : 128
    Output : 1
*/

int Solution::power(string A) {
    if (A.size() == 1) {
        if (A[0] == '1')
            return 0;
        else if (A[0] == '0')
            return 1;
    }
    while (A.size() != 1 || A[0] != '1') {
        if ((A.back() - '0') % 2 == 1)
            return 0;
        int carry = 0;
        string B;
        for (int i = 0; i < A.size(); ++i) {
            int n = 10 * carry + (A[i] - '0');
            carry = n % 2;
            n /= 2;
            if (B.size() == 0 && n == 0)
                continue;
            B.push_back('0' + n);
        }
        A = B;
    }

    return 1;
}

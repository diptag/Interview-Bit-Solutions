/*
    Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

    NOTE A solution will always exist. read Goldbach’s conjecture

    Example:


    Input : 4
    Output: 2 + 2 = 4

    If there are more than one solutions possible, return the lexicographically smaller solution.

    If [a, b] is one solution with a <= b,
    and [c,d] is another solution with c <= d, then

    [a, b] < [c, d]

    If a < c OR a==c AND b < d.
*/

vector<int> Solution::primesum(int A) {
    vector<bool> prime(A + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= A; ++i) {
        if (prime[i]) {
            for (int j = i * 2; j <= A; j += i)
                prime[j] = false;
        }
    }
    
    for (int i = 2; i * i <= A; ++i) {
        if (prime[i]) {
            int diff = A - i;
            if (prime[diff])
                return vector<int> ({i, diff});
        }
    }
    
    return vector<int> ({1, A});
}

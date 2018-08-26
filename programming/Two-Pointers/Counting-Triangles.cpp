/*
    You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
    Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

    Notes:

    You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

    Return answer modulo 109 + 7.

    For example,

    A = [1, 1, 1, 2, 2]

    Return: 4
*/

int Solution::nTriang(vector<int> &A) {
    if (A.size() < 3)
        return 0;

    int MOD = pow(10, 9) + 7;

    sort (A.begin(), A.end());
    long long count = 0;
    for (int i = 0; i < A.size() - 2; ++i) {
        int j = i + 1, k = i + 2;
        while (k < A.size()) {
            if (A[i] + A[j] > A[k]) {
                count += k - j;
                count = count % MOD;
                ++k;
            }
            else {
                ++j;
                if (j == k) ++k;
            }
        }
    }

    return count;
}

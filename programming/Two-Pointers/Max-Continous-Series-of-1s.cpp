/*
    You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
    Find the position of zeros which when flipped will produce maximum continuous series of 1s.

    For this problem, return the indices of maximum continuous series of 1s in order.

    Example:

    Input :
    Array = {1 1 0 1 1 0 0 1 1 1 }
    M = 1

    Output :
    [0, 1, 2, 3, 4]

    If there are multiple possible solutions, return the sequence which has the minimum start index.
*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int i = 0, j = 0, curFlips = 0;
    int L = 0, R = 0;
    while (i < A.size()) {
        if (A[i] == 0)
            ++curFlips;

        if (curFlips > B) {
            while (A[j] != 0) ++j;
            ++j;
            --curFlips;
        }
        else if ((i - j + 1) > (R - L + 1))
            L = j, R = i;
        ++i;
    }

    vector<int> ret;
    for (int i = L; i <= R; ++i)
        ret.push_back(i);

    return ret;
}

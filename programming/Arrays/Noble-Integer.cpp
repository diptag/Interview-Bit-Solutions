/*
    Given an integer array, find if an integer p exists in the array
    such that the number of integers greater than p in the array equals to p
    If such an integer is found return 1 else return -1.
*/

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i) {
        while (i + 1 < A.size() && A[i + 1] == A[i]) ++i;
        if (A[i] == (A.size() - 1 - i))
            return 1;
    }

    return -1;
}

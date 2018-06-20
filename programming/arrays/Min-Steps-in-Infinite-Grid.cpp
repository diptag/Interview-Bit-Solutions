int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int steps = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        int x = abs(A[i] - A[i + 1]), y = abs(B[i] - B[i + 1]);
        if (x < y)
            steps += y;
        else
            steps += x;
    }
    return steps;
}

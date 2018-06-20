int Solution::maxSubArray(const vector<int> &A) {
    int maxSum = INT_MIN, curSum = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        curSum = max(curSum + A[i], A[i]);
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}

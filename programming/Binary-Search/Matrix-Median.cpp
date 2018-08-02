/*
    Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

    For example,

    Matrix=
    [1, 3, 5]
    [2, 6, 9]
    [3, 6, 9]

    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

    Median is 5. So, we return 5.
    Note: No extra memory is allowed.
*/

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int minx = INT_MAX, maxx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            minx = min(minx, A[i][j]);
            maxx = max(maxx, A[i][j]);
        }
    }

    int nums = (n * m + 1) / 2;
    while (minx <= maxx) {
        int mid = (minx + maxx) / 2;
        int count = 0;
        for (int i = 0; i < n; ++i)
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();

        if (count == nums)
            return mid;
        else if (count > nums)
            maxx = mid;
        else
            minx = mid + 1;
    }
}


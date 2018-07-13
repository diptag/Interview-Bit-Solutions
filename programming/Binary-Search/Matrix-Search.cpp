/*
    Write an efficient algorithm that searches for a value in an m x n matrix.

    This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than or equal to the last integer of the previous row.
    Example:

    Consider the following matrix:

    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return 1 ( 1 corresponds to true )

    Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m = A.size(), n = A[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (B < A[mid][0])
            high = mid - 1;
        else if (B > A[mid][n - 1])
            low = mid + 1;
        else
        {
            int lo = 0, hi = n - 1;
            while (lo <= hi)
            {
                int md = (lo + hi) / 2;
                if (B == A[mid][md])
                    return 1;
                else if (B < A[mid][md])
                    hi = md - 1;
                else
                    lo = md + 1;
            }
            return 0;
        }
    }
    return 0;
}


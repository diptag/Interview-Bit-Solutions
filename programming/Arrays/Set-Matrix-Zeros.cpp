/*
    Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

    Do it in place.

    Example

    Given array A as

    1 0 1
    1 1 1
    1 1 1
    On returning, the array A should be :

    0 0 0
    1 0 1
    1 0 1
    Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    vector<int> rows(m, 1);
    vector<int> cols(n, 1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 0)
            {
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (rows[i] == 0)
        {
            for (int j = 0; j < n; j++)
                A[i][j] = 0;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (cols[j] == 0)
        {
            for (int i = 0; i < m; i++)
                A[i][j] = 0;
        }
    }
}

/*
    Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

    Example:

    Given the following matrix:

    [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]
    You should return

    [1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int T = 0, B = A.size() - 1, L = 0, R = A[0].size() - 1;
    int dir = 0;
    vector<int> ret;
    while (T <= B && L <= R)
    {
        if (dir == 0)
        {
            for (int i = L; i <= R; i++)
                ret.push_back(A[T][i]);
            T++;
            dir = 1;
        }
        else if (dir == 1)
        {
            for (int i = T; i <= B; i++)
                ret.push_back(A[i][R]);
            R--;
            dir = 2;
        }
        else if (dir == 2)
        {
            for (int i = R; i >= L; i--)
                ret.push_back(A[B][i]);
            B--;
            dir = 3;
        }
        else if (dir == 3)
        {
            for (int i = B; i >= T; i--)
                ret.push_back(A[i][L]);
            L++;
            dir = 0;
        }
    }

    return ret;
}

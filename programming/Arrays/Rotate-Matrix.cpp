/*
    You are given an n x n 2D matrix representing an image.

    Rotate the image by 90 degrees (clockwise).

    You need to do this in place.

    Note that if you end up using an additional array, you will only receive partial score.

    Example:

    If the array is

    [
        [1, 2],
        [3, 4]
    ]
    Then the rotated array becomes:

    [
        [3, 1],
        [4, 2]
    ]
*/

void Solution::rotate(vector<vector<int> > &A) {
    if (A.empty())
        return;

    int L = 0, R = A.size() - 1, T = 0, B = A.size() - 1;
    while (L < R && T < B)
    {
        for (int i = 0; i < (R - L); i++)
        {
            int tmp = A[T + i][R];
            A[T + i][R] = A[T][L + i];
            int tmp2 = A[B][R - i];
            A[B][R - i] = tmp;
            tmp = A[B - i][L];
            A[B - i][L] = tmp2;
            A[T][L + i] = tmp;
        }
        L++, R--, T++, B--;
    }
}

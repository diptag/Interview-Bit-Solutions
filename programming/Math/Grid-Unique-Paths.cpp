/*
    A robot is located at the top-left corner of an A x B grid (marked ‘S’ in the diagram below).

    -----------------------------
    | S |   |   |   |   |   |   |
    -----------------------------
    |   |   |   |   |   |   |   |
    -----------------------------
    |   |   |   |   |   |   | F |
    -----------------------------

    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘F’ in the diagram below).

    How many possible unique paths are there?

    Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

    Example :

    Input : A = 2, B = 2
    Output : 2

    2 possible routes : (0, 0) -> (0, 1) -> (1, 1)
                  OR  : (0, 0) -> (1, 0) -> (1, 1)
*/

int Solution::uniquePaths(int A, int B) {
    if (A == 0 || B == 0)
        return 0;

    vector <vector <int>> paths(A, vector <int> (B, 0));
    for (int i = 0; i < B; i++)
        paths[0][i] = 1;
    for (int i = 0; i < A; i++)
        paths[i][0] = 1;

    for (int i = 1; i < A; i++)
    {
        for (int j = 1; j < B; j++)
            paths[i][j] += paths[i - 1][j] + paths[i][j - 1];
    }

    return paths[A - 1][B - 1];
}

/*
    Given numRows, generate the first numRows of Pascal’s triangle.

    Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

    Example:

    Given numRows = 5,

    Return

    [
         [1],
         [1,1],
         [1,2,1],
         [1,3,3,1],
         [1,4,6,4,1]
    ]
*/

vector<vector<int> > Solution::generate(int A) {
    vector<vector<int>> ret(A, vector<int> ());
    if (A == 0)
        return ret;
    ret[0].push_back(1);
    for (int i = 1; i < A; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j - 1 < 0)
                ret[i].push_back(1);
            else if (j != i)
                ret[i].push_back(ret[i - 1][j] + ret[i - 1][j - 1]);
            else
                ret[i].push_back(1);
        }
    }
    return ret;
}

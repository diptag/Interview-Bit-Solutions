/*
    Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

    Example:

    Given n = 3,

    You should return the following matrix:

    [
      [ 1, 2, 3 ],
      [ 8, 9, 4 ],
      [ 7, 6, 5 ]
    ]
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans(A, vector<int> (A));
    if (A == 0)
        return ans;

    int t = 0, b = A - 1 , l = 0, r = A - 1;
    int flag = 1, cur_num = 1, limit = pow(A, 2);

    while (t <= b && l <= r && cur_num <= limit) {

        if (flag == 1) {
            for (int i = l; i <= r && cur_num <= limit; ++i)
                ans[t][i] = cur_num++;
            flag = 2;
            ++t;
        } else if (flag == 2) {
            for (int i = t; i <= b && cur_num <= limit; ++i)
                ans[i][r] = cur_num++;
            flag = 3;
            --r;
        } else if (flag == 3) {
            for (int i = r; i >= l && cur_num <= limit; --i)
                ans[b][i] = cur_num++;
            flag = 4;
            --b;
        } else if (flag == 4) {
            for (int i = b; i >= t && cur_num <= limit; --i)
                ans[i][l] = cur_num++;
            flag = 1;
            ++l;
        }
    }

    return ans;
}

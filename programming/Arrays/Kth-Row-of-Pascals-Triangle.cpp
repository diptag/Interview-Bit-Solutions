/*
    Given an index k, return the kth row of the Pascal’s triangle.

    Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

    Example:

    Input : k = 3

    Return : [1,3,3,1]

    NOTE : k is 0 based. k = 0, corresponds to the row [1].
    Note:Could you optimize your algorithm to use only O(k) extra space?
*/

vector<int> Solution::getRow(int k) {
    if (k == 0)
        return vector<int> ({1});

    vector<int> pre(2, 1);
    for (int i = 2; i <= k; ++i)
    {
        vector<int> cur(i + 1, 1);
        for (int j = 1; j < cur.size() - 1; ++j)
            cur[j] = pre[j] + pre[j - 1];
        pre = cur;
    }

    return pre;
}

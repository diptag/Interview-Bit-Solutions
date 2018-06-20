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

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

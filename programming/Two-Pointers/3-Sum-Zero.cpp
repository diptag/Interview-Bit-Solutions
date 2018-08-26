/*
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
    Find all unique triplets in the array which gives the sum of zero.

    Note:

     Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> ans;
    if (A.size() < 3)
        return ans;
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); ++i)
    {
        if (i > 0 && A[i] == A[i - 1])
            continue;

        int j = i + 1, k = A.size() - 1;
        while (j < k)
        {
            int sum = A[i] + A[j] + A[k];
            if (sum == 0)
            {
                ans.push_back(vector<int> ({A[i], A[j], A[k]}));
                ++j;
                while (A[j] == A[j - 1])
                    ++j;
            }
            else if (sum > 0)
                --k;
            else if (sum < 0)
                ++j;
        }
    }

    return ans;
}

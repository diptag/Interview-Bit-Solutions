/*
    Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

     Example: Input :
        A : [1 3 5]
        k : 4
     Output : YES as 5 - 1 = 4
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem

    Try doing this in less than linear space complexity.
*/

int Solution::diffPossible(vector<int> &A, int B) {
    if (A.size() <= 1)
        return 0;
    int ret = 0;
    int j = 0;
    for (int i = 0; i < A.size() && j < A.size(); ++i)
    {
        if (i == j)
            j++;
        while(A[j] - A[i] < B && j < A.size() && i != j)
            ++j;

        if (A[j] - A[i] == B && i != j)
        {
            ret = 1;
            break;
        }
    }

    return ret;
}

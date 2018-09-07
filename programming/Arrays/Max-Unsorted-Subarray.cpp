/*
    You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
    Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
    If A is already sorted, output -1.

    Example :

    Input 1:

    A = [1, 3, 2, 4, 5]

    Return: [1, 2]

    Input 2:

    A = [1, 2, 3, 4, 5]

    Return: [-1]
    In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
*/

vector<int> Solution::subUnsort(vector<int> &A) {
    int i = 1;
    for (i = 1; i < A.size() && A[i] >= A[i - 1]; ++i);
    if (i == A.size())
        return vector<int> ({-1});

    int j = A.size() - 2;
    for (; j >= 0 && A[j] <= A[j + 1]; --j);
    if (j < i)
        swap(i, j);

    int max_val = *max_element(A.begin(), A.begin() + j + 1);
    int min_val = *min_element(A.begin() + i, A.end());
    while (i - 1 >= 0 && A[i - 1] > min_val) --i;
    while (j + 1 < A.size() && A[j + 1] < max_val) ++j;

    return vector<int> ({i, j});
}

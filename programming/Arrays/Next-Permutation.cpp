/*
    Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

    If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

    The replacement must be in-place, do not allocate extra memory.

    Examples:

    1,2,3 → 1,3,2

    3,2,1 → 1,2,3

    1,1,5 → 1,5,1

    20, 50, 113 → 20, 113, 50
    Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

     Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use o
*/

void Solution::nextPermutation(vector<int> &A) {
    int i_max = 0;
    for (int i = 1; i < A.size(); ++i)
        if (A[i - 1] < A[i])
            i_max = i;

    if (i_max > 0) {
        int j_max = i_max;
        for (int j = i_max + 1; j < A.size(); ++j)
            if (A[j] > A[i_max - 1])
                j_max = j;

        int tmp = A[j_max];
        A[j_max] = A[i_max - 1];
        A[i_max - 1] = tmp;
    }

    reverse (A.begin() + i_max, A.end());
}

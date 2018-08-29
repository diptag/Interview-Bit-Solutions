/*
    Remove Element

    Given an array and a value, remove all the instances of that value in the array.
    Also return the number of elements left in the array after the operation.
    It does not matter what is left beyond the expected length.

     Example:
    If array A is [4, 1, 1, 2, 1, 3]
    and value elem is 1,
    then new length is 3, and A is now [4, 2, 3]
    Try to do it in less than linear additional space complexity.
*/

int Solution::removeElement(vector<int> &A, int B) {
    if (A.size() == 0)
        return 0;

    int j = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[j] != B)
            ++j;
        else if (A[i] != B)
        {
            int tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
            ++j;
        }
    }

    A.erase(A.begin() + j, A.end());
    return A.size();
}

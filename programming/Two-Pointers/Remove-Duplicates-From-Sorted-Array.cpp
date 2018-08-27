/*
    Remove duplicates from Sorted Array
    Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

    Note that even though we want you to return the new length, make sure to change the original array as well in place

    Do not allocate extra space for another array, you must do this in place with constant memory.

     Example:
    Given input array A = [1,1,2],
    Your function should return length = 2, and A is now [1,2].
*/

int Solution::removeDuplicates(vector<int> &A) {
    int j = 0;
    for (int i = 0; i < A.size(); ++i)
        if (A[j] != A[i])
            A[++j] = A[i];

    A.erase(A.begin() + j + 1, A.end());
    return A.size();
}

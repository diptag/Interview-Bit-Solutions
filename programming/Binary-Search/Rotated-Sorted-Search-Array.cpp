/*
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

    You are given a target value to search. If found in the array, return its index, otherwise return -1.

    You may assume no duplicate exists in the array.

    Input : [4 5 6 7 0 1 2] and target = 4
    Output : 0

    NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
*/

int Solution::search(const vector<int> &A, int B) {
    int low = 0, high = A.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[low] <= A[high])
        {
            if (B > A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if (B > A[mid])
        {
            if (A[mid] <= A[high])
            {
                if (B <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
                low = mid + 1;
        }
        else if (B < A[mid])
        {
            if (A[mid] <= A[high])
                high = mid - 1;
            else
            {
                if (B <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    return -1;
}

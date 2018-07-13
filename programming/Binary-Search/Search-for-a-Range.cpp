/*
    Given a sorted array of integers, find the starting and ending position of a given target value.

    Your algorithm’s runtime complexity must be in the order of O(log n).

    If the target is not found in the array, return [-1, -1].

    Example:

    Given [5, 7, 7, 8, 8, 10]

    and target value 8,

    return [3, 4].
*/

bool binarySearch (const vector<int> &A, int B, vector<int> &C, int low, int high) {
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == B)
        {
            if (mid == 0 || (mid > 0 && A[mid - 1] < B))
            {
                C[0] = mid;
                if (C[1] == -1)
                    if (binarySearch (A, B, C, mid + 1, high))
                        return true;
            }
            else if (mid == A.size() - 1 || (mid < A.size() - 1 && A[mid + 1] > B))
            {
                C[1] = mid;
                if (C[0] == -1)
                    if (binarySearch(A, B, C, low, mid - 1))
                        return true;
            }
            else
                if (binarySearch(A, B, low, mid - 1))
        }
        else if (A[mid] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    if (A.size() == 0)
        return vector<int> ({-1, -1});

    int low = 0, high = A.size() - 1;
}

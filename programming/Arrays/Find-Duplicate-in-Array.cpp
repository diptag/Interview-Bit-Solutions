/*
    Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

    Sample Input:

    [3 4 1 4 1]
    Sample Output:

    1
    If there are multiple possible answers ( like in the sample case above ), output any one.

    If there is no duplicate, output -1
*/

int Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() <= 1)
        return -1;

    int slow = A.back();
    int fast = A[slow - 1];
    while (slow != fast) {
        slow=A[slow - 1];
        fast=A[A[fast - 1] - 1];
    }
    slow = A.size();
    while (slow != fast) {
        slow = A[slow - 1];
        fast = A[fast - 1];
    }
    return slow;
}

/*
    Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

    Example:

    Input : [1, 0]
    Return : [0, 1]
     Lets say N = size of the array. Then, following holds true :
    All elements in the array are in the range [0, N-1]
    N * N does not overflow for a signed integer
*/

void Solution::arrange(vector<int> &A) {
    for (int i = 0; i < A.size(); i++)
        A[i] *= 10;

    int index = 0;
    while(index < A.size())
    {
        while (A[index] % 10 != 0 && index < A.size())
            index++;

        if (A[index] % 10 == 0 && index < A.size())
        {
            int cur = index;
            int next = A[cur] / 10;
            while (next != index)
            {
                int tmp = A[cur];
                A[cur] = A[next];
                A[next] = tmp;
                A[cur] += 1;
                tmp = A[cur] / 10;
                cur = next;
                next = tmp;
            }
            if (A[cur] % 10 == 0)
                A[cur] += 1;
        }
    }

    for (int i = 0; i < A.size(); i++)
        A[i] /= 10;
}

/*
    Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

    NOTE: All numbers can only have digits from the given set.
    Examples:

        Input:
          0 1 5
          1
          2
        Output:
          2 (0 and 1 are possible)

        Input:
          0 1 2 5
          2
          21
        Output:
          5 (10, 11, 12, 15, 20 are possible)
    Constraints:
        1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9
*/

int Solution::solve(vector<int> &A, int B, int C) {
    if (C == 0)
        return 0;

    int digits = 0;
    int n = C;
    while (n > 0)
    {
        n /= 10;
        digits++;
    }

    if (B < digits)
    {
        if (find(A.begin(), A.end(), 0) != A.end() && B != 1)
            return (A.size() - 1) * pow(A.size(), B - 1);
        else
            return pow(A.size(), B);
    }
    else if (B > digits)
        return 0;

    int ret = 0, flag = 1;

    for (int i = digits - 1; i >= 0; i--)
    {
        int d = (int)(C / pow(10, i)) % 10;
        if (flag == 1)
        {
            flag = 0;
            int count = 0;
            int zero = 0;
            for (int a: A)
            {
                if (a < d)
                    count++;

                if (a == d)
                    flag = 1;

                if (a == 0)
                    zero = 1;
            }
            if (zero == 1 && i == digits - 1 && B != 1)
                ret += (count - 1) * pow(A.size(), i);
            else
                ret += count * pow(A.size(), i);
        }
    }

    return ret;
}

/*
    Given two binary strings, return their sum (also a binary string).

    Example:

    a = "100"

    b = "11"
    Return a + b = “111”.
*/

string Solution::addBinary(string A, string B) {
    int i = A.size() - 1, j = B.size() - 1;
    int carry = 0;
    string ans;
    while (i >= 0 && j >= 0)
    {
        int sum = (A[i] - '0') + (B[j] - '0') + carry;
        if (sum == 0 || sum == 2)
            ans.push_back('0');
        else if (sum == 1 || sum == 3)
            ans.push_back('1');

        if (sum == 2 || sum == 3)
            carry = 1;
        else
            carry = 0;
        --i, --j;
    }

    while (i < 0 && j >= 0)
    {
        int sum = (B[j] - '0') + carry;
        if (sum == 0 || sum == 2)
            ans.push_back('0');
        else if (sum == 1)
            ans.push_back('1');

        if (sum == 2)
            carry = 1;
        else
            carry = 0;
        --j;
    }

    while (j < 0 && i >= 0)
    {
        int sum = (A[i] - '0') + carry;
        if (sum == 0 || sum == 2)
            ans.push_back('0');
        else if (sum == 1)
            ans.push_back('1');

        if (sum == 2)
            carry = 1;
        else
            carry = 0;
        --i;
    }

    if (carry == 1)
        ans.push_back('1');

    reverse (ans.begin(), ans.end());

    return ans;
}

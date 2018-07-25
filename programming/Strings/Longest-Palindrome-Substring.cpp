/*
    Given a string S, find the longest palindromic substring in S.

    Substring of string S:

    S[i...j] where 0 <= i <= j < len(S)

    Palindrome string:

    A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

    Incase of conflict, return the substring which occurs first ( with the least starting index ).

    Example :

    Input : "aaaabaaa"
    Output : "aaabaaa"
*/

string Solution::longestPalindrome(string str) {

    int n = str.size();
    vector<vector<bool>> table(n, vector<bool> (n));

    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n-k+1 ; ++i)
        {
            int j = i + k - 1;

            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    string ret;
    for (int i = 0; i < maxLength; i++)
        ret.push_back(str[start + i]);

    return ret;
}

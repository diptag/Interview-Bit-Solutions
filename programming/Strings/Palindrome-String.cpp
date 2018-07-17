/*
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Example:

    "A man, a plan, a canal: Panama" is a palindrome.

    "race a car" is not a palindrome.

    Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isPalindrome(string A) {
    int i = 0, j = A.size() - 1;
    while (i <= j)
    {
        if (isalpha(A[i]) && isalpha(A[j]))
        {
            char a = tolower(A[i]);
            char b = tolower(A[j]);
            if (a != b)
                return 0;
            else
            {
                ++i;
                --j;
            }
        }
        else if (isalpha(A[i]))
            --j;
        else
            ++i;
    }

    return 1;
}

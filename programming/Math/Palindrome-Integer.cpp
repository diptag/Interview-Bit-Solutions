/*
    Determine whether an integer is a palindrome. Do this without extra space.

    A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
    Negative numbers are not palindromic.

    Example :

    Input : 12121
    Output : True

    Input : 123
    Output : False
*/

int Solution::isPalindrome(int A) {
    if (A < 0)
        return 0;
    int n = A, d = 10, a = 0;
    while (n > 0)
    {
        n /= d;
        a++;
    }
    int i = 0, j = a - 1;
    while (j > i)
    {
        int e = (A / (int)pow(10, j--)) % 10;
        int f = (A / (int)pow(10, i++)) % 10;
        if (e != f)
            return 0;
    }
    return 1;
}


/*
    Given a roman numeral, convert it to an integer.

    Input is guaranteed to be within the range from 1 to 3999.

    Read more details about roman numerals at Roman Numeric System

    Example :

    Input : "XIV"
    Return : 14
    Input : "XX"
    Output : 20
*/

int resolve_roman (char c)
{
    switch (c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}

int Solution::romanToInt(string A) {
    int num = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int n = resolve_roman(A[i]);
        if (i > 0)
        {
            int pre = resolve_roman(A[i - 1]);
            if (pre < n)
                n -= 2 * pre;
        }
        num += n;
    }
    return num;
}

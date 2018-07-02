/*
    Given a column title as appears in an Excel sheet, return its corresponding column number.

    Example:

        A -> 1

        B -> 2

        C -> 3

        ...

        Z -> 26

        AA -> 27

        AB -> 28
*/

int Solution::titleToNumber(string A) {
    if (A.empty())
        return 0;

    int ret = 0;
    for (int i = 0; i < A.size(); i++)
        ret += (*(A.rbegin() + i) - 64) * pow(26, i);
    return ret;
}

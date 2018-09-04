/*
    Given a positive integer, return its corresponding column title as appear in an Excel sheet.

    For example:

        1 -> A
        2 -> B
        3 -> C
        ...
        26 -> Z
        27 -> AA
        28 -> AB
*/

string Solution::convertToTitle(int A) {
    string ret;
    while (A > 0) {
        int r = A % 26;
        A /= 26;
        if (r > 0)
            ret.push_back('A' + (r - 1));
        else {
            ret.push_back('Z');
            A--;
        }
    }
    reverse (ret.begin(), ret.end());

    return ret;
}

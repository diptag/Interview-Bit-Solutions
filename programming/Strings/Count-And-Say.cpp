/*
    The count-and-say sequence is the sequence of integers beginning as follows:

    1, 11, 21, 1211, 111221, ...
    1 is read off as one 1 or 11.
    11 is read off as two 1s or 21.

    21 is read off as one 2, then one 1 or 1211.

    Given an integer n, generate the nth sequence.

    Note: The sequence of integers will be represented as a string.

    Example:

    if n = 2,
    the sequence is 11.
*/

string Solution::countAndSay(int A) {
    string pre = "1";
    for (int i = 1; i < A; ++i) {
        string next;
        int j = 0;
        while (j < pre.size()) {
            char c = pre[j++];
            int count = 1;
            while (j < pre.size() && pre[j] == c)
                ++count, ++j;
            next.push_back('0' + count);
            next.push_back(c);
        }
        pre = next;
    }

    return pre;
}

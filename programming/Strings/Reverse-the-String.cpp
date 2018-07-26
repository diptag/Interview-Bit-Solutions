/*
    Given an input string, reverse the string word by word.

    Example:

    Given s = "the sky is blue",

    return "blue is sky the".

    A sequence of non-space characters constitutes a word.
    Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
    If there are multiple spaces between words, reduce them to a single space in the reversed string.
*/

void Solution::reverseWords(string &A) {
    if (A.empty())
        return;

    stack<string> st;
    string B;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == ' ' && !B.empty()) {
            st.push(B);
            B.clear();
        }
        else if (A[i] != ' ')
            B.push_back(A[i]);
    }
    if (!B.empty())
        st.push(B);

    A.clear();
    while (!st.empty()) {
        if (!A.empty())
            A.push_back(' ');
        A.append(st.top());
        st.pop();
    }
}

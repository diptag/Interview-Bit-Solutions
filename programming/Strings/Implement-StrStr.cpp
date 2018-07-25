/*
    Implement strStr().

     strstr - locate a substring ( needle ) in a string ( haystack ).
    Try not to use standard library string functions for this question.

    Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

     NOTE: Good clarification questions:
    What should be the return value if the needle is empty?
    What if both haystack and needle are empty?
    For the purpose of this problem, assume that the return value should be -1 in both cases.
*/

int Solution::strStr(const string A, const string B) {

    int index = -1;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == B[0])
        {
            bool isstr = true;
            int next = 0;
            for (int j = 1; j < B.size(); j++)
            {
                if (i + j > A.size() || A[i + j] != B[j])
                {
                    isstr = false;
                    break;
                }
            }
            if (isstr)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

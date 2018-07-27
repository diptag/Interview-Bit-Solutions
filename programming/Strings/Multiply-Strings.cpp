/*
    Given two numbers represented as strings, return multiplication of the numbers as a string.

    Note: The numbers can be arbitrarily large and are non-negative.
    Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer.
    For example,
    given strings "12", "10", your answer should be “120”.

    NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ).
*/

string Solution::multiply(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string res;
    res.resize(A.size() + B.size(), '0');
    for (int i = 0; i < A.size(); ++i) {
        int p = 0;
        for (int j = 0; j < B.size() || p; ++j) {
            int val = res[i+j]-'0';
            int mul = 0;
            if (j < B.size()) {
                mul = (B[j] - '0');
            }
            val+=(A[i]-'0')*mul+p;
            p=val/10;
            val%=10;
            res[i+j]=(val+'0');
        }
    }
    while ((res.size() > 1) && (res[res.size() - 1] == '0'))
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

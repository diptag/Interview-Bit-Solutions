/*
    Given an array of real numbers greater than zero in form of strings.
    Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
    Return 1 for true or 0 for false.

    Example:

    Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

    You should return 1

    as

    0.6+0.7+0.4=1.7

    1<1.7<2

    Hence, the output is 1.

    O(n) solution is expected.

    Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
*/

int Solution::solve(vector<string> &A) {
    if (A.size() < 3)
        return 0;

    vector<double> B(A.size());
    for (int i = 0; i < A.size(); ++i)
        B[i] = stod(A[i]);

    bool exists = false;
    double a = B[0], b = B[1], c = B[2];
    for (int i = 3; i < A.size() && !exists; ++i) {
        double sum = a + b + c;
        if (sum > 1 && sum < 2)
            exists = true;
        else if (sum > 2) {
            if (a > b && a > c)
                a = B[i];
            else if (b > a && b > c)
                b = B[i];
            else
                c = B[i];
        }
        else {
            if (a < b && a < c)
                a = B[i];
            else if (b < a && b < c)
                b = B[i];
            else
                c = B[i];
        }
    }

    if (exists)
        return 1;
    else
        return 0;
}

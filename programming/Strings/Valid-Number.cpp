/*
    Validate if a given string is numeric.

    Examples:

    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem

    Clarify the question using “See Expected Output”

    Is 1u ( which may be a representation for unsigned integers valid?
    For this problem, no.
    Is 0.1e10 valid?
    Yes
    -01.1e-10?
    Yes
    Hexadecimal numbers like 0xFF?
    Not for the purpose of this problem
    3. (. not followed by a digit)?
    No
    Can exponent have decimal numbers? 3e0.1?
    Not for this problem.
    Is 1f ( floating point number with f as prefix ) valid?
    Not for this problem.
    How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
    Not for this problem.
    How about integers preceded by 00 or 0? like 008?
    Yes for this problem
*/

int Solution::isNumber(const string A) {
    if (A.empty())
        return 0;
    bool dot = false, e_char = false, is_valid = true;
    int index = 0;
    while (index < A.size() && A[index] == ' ') ++index;
    int back_index = A.size() - 1;
    while (back_index >= 0 && A[back_index] == ' ') --back_index;
    if (index == A.size())
        return 0;

    for (int i = index; i <= back_index; ++i) {
        if ((A[i] == '+' || A[i] == '-') && (i == 0 || A[i - 1] == 'e')) {
            if (i == back_index)
                is_valid = false;
        }
        else if (A[i] == '.' && !dot && !e_char) {
            dot = true;
            if (i == back_index || A[i + 1] < '0' || A[i + 1] > '9')
                is_valid = false;
        }
        else if (A[i] == 'e' && !e_char) {
            e_char = true;
            if (i == back_index)
                is_valid = false;
        }
        else if (A[i] < '0' || A[i] > '9')
            is_valid = false;

        if (!is_valid)
            break;
    }

    if (is_valid)
        return 1;
    else
        return 0;
}

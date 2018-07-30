/*
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P.......A........H.......N
    ..A..P....L....S....I...I....G
    ....Y.........I........R
    And then read line by line: PAHNAPLSIIGYIR
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
    **Example 2 : **
    ABCD, 2 can be written as

    A....C
    ...B....D
    and hence the answer would be ACBD.
*/

string Solution::convert(string A, int B) {
    if (B == 1)
        return A;

    string ans;
    int level = 1, flag = 1, start = 0, i = 0;
    while (ans.size() < A.size()) {
        ans.push_back(A[i]);
        if (level != 1) {
            if (flag == 1)
                i += 2 * (B - level);
            else
                i += 2 * (level - 1);
            flag = !flag;
        }
        else
            i += 2 * (B - 1);

        if (i >= A.size()) {
            i = ++start;
            flag = 1;
            level++;
            if (level == B)
                level = 1;
        }
    }

    return ans;
}

/*
    Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

    Input is guaranteed to be within the range from 1 to 3999.

    Example :

    Input : 5
    Return : "V"

    Input : 14
    Return : "XIV"
    Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.
*/

string Solution::intToRoman(int num) {
    string M[] = {"", "M", "MM", "MMM"};

    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

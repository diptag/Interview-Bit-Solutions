/*
    Given an array of integers, every element appears thrice except for one which occurs once.

    Find that element which does not appear thrice.

    Note: Your algorithm should have a linear runtime complexity.

    Could you implement it without using extra memory?

    Example :

    Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
    Output : 4
*/

int Solution::singleNumber(const vector<int> &A) {
    if (A.size() == 0) {
        return 0;
    }

    int first = 0, second = 0;
    for(int i = 0; i < A.size(); i++){
        second = second | (first & A[i]);
        first = first ^ A[i];
        int check = ~(first & second);
        first = first & check;
        second = second & check;
    }

    return first;
}

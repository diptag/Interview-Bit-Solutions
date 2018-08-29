/*
    Given an array with n objects colored red, white or blue,
    sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

    Note: Using library sort function is not allowed.

    Example :

    Input : [0 1 2 0 1 2]
    Modify array so that it becomes : [0 0 1 1 2 2]
*/

void Solution::sortColors(vector<int> &A) {
    int zeros = 0, ones = 0, twos = 0;
    for (int i: A)
    {
        if (i == 0)
            ++zeros;
        else if (i == 1)
            ++ones;
        else if (i == 2)
            ++twos;
    }
    A.clear();
    while(zeros--)
        A.push_back(0);
    while(ones--)
        A.push_back(1);
    while(twos--)
        A.push_back(2);
}

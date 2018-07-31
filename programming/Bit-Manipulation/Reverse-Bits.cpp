/*
    Reverse bits of an 32 bit unsigned integer

    Example 1:

    x = 0,

              00000000000000000000000000000000
    =>        00000000000000000000000000000000
    return 0

    Example 2:

    x = 3,

              00000000000000000000000000000011
    =>        11000000000000000000000000000000
    return 3221225472

    Since java does not have unsigned int, use long
*/

unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans = 0;
    for (int i = 0; i < 32; ++i)
    {
        if (A & 1 << i)
            ans = ans | 1 << (31 - i);
    }

    return ans;
}

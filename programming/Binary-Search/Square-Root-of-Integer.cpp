/*
    Implement int sqrt(int x).

    Compute and return the square root of x.

    If x is not a perfect square, return floor(sqrt(x))

    Example :

    Input : 11
    Output : 3
    DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
*/

int Solution::sqrt(int A) {
    if (A <= 0)
        return 0;

    int low = 1;
    int high = A / 2;

    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (mid == A / mid)
            return mid;
        else if (mid > A / mid)
            high = mid - 1;
        else if (mid < A / mid)
        {
            if (mid + 1 > A / (mid + 1))
                return mid;
            else
                low = mid + 1;
        }
    }
}

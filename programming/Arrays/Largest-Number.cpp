/*
    Given a list of non negative integers, arrange them such that they form the largest number.

    For example:

    Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

    Note: The result may be very large, so you need to return a string instead of an integer.
*/

bool compare (string a, string b) {
    string xy = a + b, yx = b + a;
    return xy.compare(yx) > 0 ? true : false;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> nums;
    for (int a: A)
        nums.push_back(to_string(a));

    sort (nums.begin(), nums.end(), compare);
    string ret;
    for (string s: nums)
        ret.append(s);
    int i = -1;
    while ( i + 1 < ret.size() && ret[i + 1] == '0') ++i;
    if (i > -1)
        ret.erase(ret.begin(), ret.begin() + i);

    return ret;
}

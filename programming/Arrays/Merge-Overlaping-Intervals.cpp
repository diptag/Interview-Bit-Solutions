/*
    Given a collection of intervals, merge all overlapping intervals.

    For example:

    Given [1,3],[2,6],[8,10],[15,18],

    return [1,6],[8,10],[15,18].

    Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), [](Interval a, Interval b) { return (a.start < b.start); });

    vector<Interval> ans;
    ans.push_back(A[0]);
    for (int i = 1; i < A.size(); ++i) {
        if (A[i].start > ans.back().end)
            ans.push_back(A[i]);
        else if (A[i].start <= ans.back().end && A[i].end > ans.back().end)
            ans.back().end = A[i].end;
    }

    return ans;
}

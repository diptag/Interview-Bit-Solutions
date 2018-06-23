/*
    Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

    You may assume that the intervals were initially sorted according to their start times.

    Example 1:

    Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

    Example 2:

    Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

    This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

    Make sure the returned intervals are also sorted.
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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ret;
    if (newInterval.start > newInterval.end) {
        int tmp = newInterval.start;
        newInterval.start = newInterval.end;
        newInterval.end = tmp;
    }

    if (intervals.empty())
        ret.push_back(newInterval);
    else if (newInterval.end < intervals[0].start) {
        ret.insert(ret.begin(), newInterval);
        ret.insert(ret.begin() + 1, intervals.begin(), intervals.end());
    }
    else if (newInterval.start > intervals[intervals.size() - 1].end) {
        ret.insert(ret.begin(), intervals.begin(), intervals.end());
        ret.push_back(newInterval);
    }
    else if (newInterval.start < intervals[0].start && newInterval.end > intervals[intervals.size() - 1].end)
        ret.push_back(newInterval);
    else {
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.start > intervals[i].end)
                ret.push_back(intervals[i]);
            else if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) {
                newInterval.start = intervals[i].start;
                if (newInterval.end <= intervals[i].end)
                    ret.push_back(intervals[i]);
            }
            else if (newInterval.start < intervals[i].start) {
                if (newInterval.end > intervals[i].end)
                    continue;
                else if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) {
                    newInterval.end = intervals[i].end;
                    ret.push_back(newInterval);
                }
                else {
                    if (newInterval.end > intervals[i - 1].end) {
                        ret.push_back(newInterval);
                        ret.push_back(intervals[i]);
                    }
                    else
                        ret.push_back(intervals[i]);
                }
            }
        }
        if (newInterval.end > intervals[intervals.size() - 1].end)
            ret.push_back(newInterval);
    }
    return ret;
}

//
// Merge Intervals
// https://leetcode.com/problems/merge-intervals/#/description
//

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    void quick_sort(vector<Interval>& intervals, int begin, int end)
    {
        Interval p = intervals[begin];
        int i = begin;
        int j = end;
        while (1) {
            while (j > i && intervals[j].start >= p.start)
                --j;
            if (i == j)
                break;
            intervals[i] = intervals[j];
            while (i < j && intervals[i].start <= p.start)
                ++i;
            if (i == j)
                break;
            intervals[j] = intervals[i];
        }
        intervals[i] = p;
        if (begin < i - 1)
            quick_sort(intervals, begin, i - 1);
        if (j + 1 < end)
            quick_sort(intervals, j + 1, end);
    }
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> ret;
        if (intervals.size() == 0)
            return ret;

        quick_sort(intervals, 0, intervals.size() - 1);

        bool goon;
        int idx = 0;
        while (1) {
            int start = intervals[idx].start;
            int end = intervals[idx].end;
            goon = false;
            for (int i  = idx + 1; i < intervals.size(); ++i) {
                if (intervals[i].start <= end) {
                    if (end < intervals[i].end)
                        end = intervals[i].end;
                } else {
                    idx = i;
                    goon = true;
                    break;
                }
            }
            ret.push_back(Interval(start, end));
            if (!goon)
                break;
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(15, 18));

    Solution sol;
    vector<Interval> ret = sol.merge(intervals);
    for (int i = 0; i < ret.size(); ++i)
        printf("%d, %d\n", ret[i].start, ret[i].end);

    return 0;
}
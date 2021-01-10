/*
贪心，按开始时间升序排序，然后遍历一遍即可，下面演示了sort使用匿名函数进行排序的方法。

*/



/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        int last = -1;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        for(auto interval: intervals) {
            if (interval.start < last) return false;
            last = interval.end;
        }
        return true;
    }
};
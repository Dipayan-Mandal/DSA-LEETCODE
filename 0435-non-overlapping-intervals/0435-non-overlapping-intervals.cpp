class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int count = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < prevEnd) {
                // overlap, remove current interval
                count++;
            }
            else {
                // no overlap
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};
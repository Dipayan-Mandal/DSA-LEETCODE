bool cmp(vector<int> &a,vector<int> &b)
{
    return a[1]<b[1];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        vector<vector<int>> result;
        result.push_back(intervals[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(intervals[i][1]>=result.back()[0])
            {
                result.back()[0]=min(intervals[i][0],result.back()[0]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
           
        }
         reverse(result.begin(), result.end());
        return result;
    }
};
class Solution {
public:
    typedef pair<int,pair<int,int>> pip;
    vector<int> smallestRange(vector<vector<int>>& arr) {
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(maxi,arr[i][0]);
            pq.push({arr[i][0],{i,0}}); 
        }
        int mini=pq.top().first;
        int start=mini;int end=maxi;
        while(true)
        {
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col==arr[row].size()-1) break;
            pq.push({arr[row][col+1],{row,col+1}});
            maxi=max(maxi,arr[row][col+1]);
            mini=pq.top().first;
            if(maxi-mini<end-start)
            {
                end=maxi;
                start=mini;
            }
        }
        return {start,end};

    }
};
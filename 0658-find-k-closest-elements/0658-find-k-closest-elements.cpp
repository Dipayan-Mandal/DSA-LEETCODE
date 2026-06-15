class Solution {
public:
typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        unordered_map<int,int> m;
        int n=arr.size();
        vector<int> ans;
       
        
        priority_queue<pair<int,int>> pq;
        for(auto num: arr)
        {
            pq.push({abs(num - x),num});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:nums)
        {
            pq.push(x);
        }
        //if(pq.top()==0) 
        while(k--){
        int ele=pq.top();
        pq.pop();
        pq.push(ele*-1);
        }
        int sum=0;
        while(pq.size()>0)
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
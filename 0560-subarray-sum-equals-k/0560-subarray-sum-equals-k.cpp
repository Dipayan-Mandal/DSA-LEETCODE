class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        vector<int> pre(n,0);
        int count=0;
        
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        for(auto x:pre)
        {
            if(x==k) count++;
            int rem=x-k;
            if(mp.find(rem)!=mp.end()) count+=mp[rem];
            mp[x]++;
        }
        return count;
    }
};
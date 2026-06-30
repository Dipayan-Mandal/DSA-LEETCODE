class Solution {
public:

    void subset2(vector<int>& nums,int n,int idx,vector<int> ans,vector<vector<int>> &v)
    {
        if(idx==n){
        v.push_back(ans);
        return;
        }
        subset2(nums,n,idx+1,ans,v);
        ans.push_back(nums[idx]);
        subset2(nums,n,idx+1,ans,v);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> v;
        int n=nums.size();
        int idx=0;
        subset2(nums,n,idx,ans,v);
        return v;
    }
};
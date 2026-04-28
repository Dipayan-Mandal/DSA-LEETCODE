class Solution {
public:

    void sum(vector<int> v,int n,int target,int idx,vector<int> &arr,vector<vector<int>> &ans)
    {
        
        if(target==0)
        {
            ans.push_back(v);
            return;
        }

        if(target<0) return;

        for(int i=idx;i<n;i++)
        {
            v.push_back(arr[i]);
            sum(v,n,target-arr[i],i,arr,ans);
            v.pop_back();
        }
        

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        int n=candidates.size();
        int idx=0;
        vector<vector<int>> ans;
        sum(v,n,target,idx,candidates,ans);
        return ans;
    }
};
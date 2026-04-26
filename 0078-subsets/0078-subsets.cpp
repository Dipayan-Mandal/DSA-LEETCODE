class Solution {
public:
    void remove(vector<int>& nums, vector<int> ans,
                vector<vector<int>> &finalans, int idx) {
        if (idx >= nums.size()) {
            finalans.push_back(ans);
            return;
        }

        remove(nums, ans, finalans, idx+1);
        ans.push_back(nums[idx]);
        remove(nums, ans, finalans, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> finalans;
        int idx = 0;
        remove(nums, ans, finalans, idx);
    return finalans;
}
};
class Solution {
public:

    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& temp) {
        // Store the current subset
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);      // Choose
            solve(i + 1, nums, temp);     // Recurse
            temp.pop_back();              // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(0, nums, temp);

        return ans;
    }
};
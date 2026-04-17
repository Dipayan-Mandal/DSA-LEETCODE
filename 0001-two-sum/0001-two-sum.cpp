class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size();i++){
            for(j=i+1;j<nums.size();j++)
            {
                int sum= nums[i]+nums[j];
                if(sum==target)
                 return {i,j};
            }
        }
        return {};
    }
};
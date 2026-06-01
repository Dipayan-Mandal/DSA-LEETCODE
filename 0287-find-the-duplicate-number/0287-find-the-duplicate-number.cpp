class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            int correctidx=nums[i]-1;
            if(nums[correctidx]==nums[i]){ if(i!=correctidx) return nums[i];i++;}
            else swap(nums[i],nums[correctidx]);
        }
        return 100;
    }
};
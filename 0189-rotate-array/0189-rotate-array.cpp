class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //4321765
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
        //3 -100 -1 99
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int Minlen=INT_MAX;
        int len;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                sum-=nums[i];
                len=j-i+1;
                Minlen=min(len,Minlen);
                i++;
            }
            j++;
        }
        if(Minlen==INT_MAX) return 0;
        return Minlen;
    }
};
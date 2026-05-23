class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int x=-1,y=-1;
         bool flag=false;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            {
                if(mid == 0 || nums[mid-1]!=target) {x=mid; flag=true; break;}
                else hi=mid-1;
            }
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;     
        }
        lo=0;
         hi=n-1;
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            {
                if(mid == n - 1 || nums[mid+1]!=target) {y=mid; flag=true;
                break;}
                else lo=mid+1;
            }
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;     
        }
        if(flag==true) return {x,y};
        else return {-1,-1};

    }
};
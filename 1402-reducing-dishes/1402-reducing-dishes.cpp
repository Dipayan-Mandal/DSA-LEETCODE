class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end());
        //-9 -8 -1 0 5
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            nums[i]=sat[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            nums[i]+=nums[i+1];
        }
        // -13 -4 4 5 5
        int j=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                j=i;
                break;
            }
            
        }
       if(j==-1) return 0;
        int x=1;
        int sum=0;
        for(int i=j;i<n;i++)
        {
            sum+=(sat[i]*x);
            x++;
        }
    return sum;
    }
};
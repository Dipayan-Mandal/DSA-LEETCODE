class Solution {
public:
    bool check(int mid,vector<int> weights,int days)
    {
        int n=weights.size();
        int count=1;
        int m=mid;
        for(int i=0;i<n;i++)
        {
            if(m>=weights[i])
            {
                m-=weights[i];
            }
            else
            {
                count++;
                m=mid;
                m-=weights[i];
            }
        }
        if(count>days) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        int n=weights.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int lo=maxi;
        int hi=sum;
        int mincapa=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(mid,weights,days))
            {
                mincapa=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return mincapa;
    }
};
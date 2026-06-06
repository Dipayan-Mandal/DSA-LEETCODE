class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int n) {
        int prevloss=0;
        int maxsum=INT_MIN;
        int idx=0;
        for(int i=0;i<n;i++)
        {
            if (grumpy[i]==1)
            prevloss+=customers[i];
        }
        maxsum=prevloss;
        int i=1;
        int j=n;
        while(j<grumpy.size())
        {
            int curloss=prevloss;
            if (grumpy[j]==1)
            curloss+=customers[j];
            if (grumpy[i-1]==1)
            curloss-=customers[i-1];
            if(maxsum<curloss)
            {
                maxsum=curloss;
                idx=i;
            }
            prevloss = curloss; 
            i++;
            j++;
        }
        
        for(int i=idx;i<idx+n;i++)
        {
            if(grumpy[i]==1) grumpy[i]=0;
        }
        int sum=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i]==0)
            {
                sum+=customers[i];
            }
        }
        return sum;
    }
};
class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        int pre[n+1];
        int suf[n+1];
        pre[0]=0;
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='Y')
            pre[i]=pre[i-1]+c;
            else
            {
                pre[i]=pre[i-1]+1;
            }
        }
        suf[n]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='Y')
            {
                suf[i]=suf[i+1]+1;
            }
            else
            suf[i]=suf[i+1];
        }
        int mini=INT_MAX;
        int j=0;
        for(int i=0;i<=n;i++)
        {
            suf[i]=pre[i]+suf[i];
            if(suf[i]<mini)
            {
                mini=suf[i];
                j=i;
            }
        }
        return j;

    }
};
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        //5 6 7 8
        //7 8 9 10
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]>=g[0]){
            idx=i;
            break;
            }
        }
        if(idx==-1) return 0;
        int i=0;
        int j=idx;
        int c=0;
        
        while(i<m && j<n)
        {
            if(s[j]>=g[i]){
            c++; i++;j++;
            }
            else
            {
                j++;
            }
        }
        return c;

    }
};
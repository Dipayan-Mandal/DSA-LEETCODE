class Solution {
public:

    int  rev(int n)
    {
        int r=0;
        while(n>0)
        {
            r*=10;
            r+=(n%10);
            n/=10;
        }
        return r;
    }

    int countDistinctIntegers(vector<int>& arr) {
        unordered_set<int> s;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            s.insert(rev(arr[i]));
        }
        return s.size();
    }
};
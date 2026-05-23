class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        while(n)
        {
            if(s[i]!=t[i]) 
            {
                return false;
                break;
            }
            n--;
            i++;
        }
        return true;

    }
};
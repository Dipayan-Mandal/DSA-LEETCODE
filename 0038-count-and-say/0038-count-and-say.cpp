class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str=countAndSay(n-1);
        // 3322251  // 23 32 15 11

        string s="";
        char ch=str[0];
        int freq=1;
        for(int i=1;i<str.length();i++)
        {
            char dh=str[i];
            if(ch==dh)
            {
                freq++;
            }
            else
            {
                s+=(to_string(freq)+ch);
                ch=str[i];
                freq=1;
            }
        }
        s+=(to_string(freq)+ch);
        return s;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto str:arr)
        {
            string lexo=str;
            sort(lexo.begin(),lexo.end());
            if(mp.find(lexo)==mp.end())
            {
                vector<string> v;
                v.push_back(str);
                mp[lexo]=v;
            }
            else
            {
                mp[lexo].push_back(str);
            }
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
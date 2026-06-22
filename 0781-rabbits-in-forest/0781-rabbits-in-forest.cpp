class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();
        int count = 0;
        for (auto x : arr) {
            mp[x]++;
        }
        for (auto x : mp) {
            if (x.first == 0) {
                count += x.second; // each rabbit is alone
            } else if (x.second < x.first + 1) {
                count += x.first + 1;
            } else if (x.second == x.first + 1) {
                count += x.first + 1;
                // mp[arr[i]]=0;
            } else {
                if ((x.second) % (x.first + 1) == 0)
                    count += (x.first + 1) * ((x.second) / (x.first + 1));
                else
                    count += (x.first + 1) * (((x.second) / (x.first + 1)) + 1);
            }
        }
        return count;
    }
};
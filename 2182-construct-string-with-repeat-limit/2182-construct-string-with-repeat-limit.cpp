class Solution {
public:
    string repeatLimitedString(string s, int k) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<char, int>> pq;
        for (auto x : mp) {
            pq.push(x);
        }
        string result = "";
        while (pq.size()) {
            auto largest = pq.top();
            pq.pop();
            int mini = min(largest.second, k);
            for (int i = 0; i < mini; i++) {
                result += largest.first;
            }
            largest.second -= mini;
            pair<char, int> seclargest;
            if (largest.second > 0) {
                if (pq.empty())
                    break;

                seclargest = pq.top();
                pq.pop();
                result += seclargest.first;
                seclargest.second--;

                pq.push(largest);

                if (seclargest.second > 0)
                    pq.push(seclargest);
            }
        }
        return result;
    }
};

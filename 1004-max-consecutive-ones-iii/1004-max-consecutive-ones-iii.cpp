class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int flip = 0;
        int maxLen = INT_MIN;
        int len = 0;
        while (j < n) {
            if (arr[j] == 1)
                j++;
            else {
                if (k > flip) {
                    flip++;
                    j++;
                } else {
                    len = j - i;
                    maxLen = max(len, maxLen);
                    while (arr[i] == 1)
                        i++;
                    i++;
                    flip--;
                }
            }
        }
        len = j - i;
        maxLen = max(len, maxLen);
        return maxLen;
    }
};
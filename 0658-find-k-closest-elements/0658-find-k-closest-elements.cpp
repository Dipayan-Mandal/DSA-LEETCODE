class Solution {
public:
    int bs(vector<int>& arr, int target) {
        int x = target;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] < x)
                low = mid + 1;

            else
                high = mid - 1;
        }
        return low;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        int n = arr.size();
        int idx = bs(arr, x);
        if (idx == -1) {
            for (int i = 0; i < k; i++) {
                v.push_back(arr[i]);
            }
        } else {
            int lb, up;

            if (idx < n && arr[idx] == x) {

                v.push_back(arr[idx]);
                k--;

                lb = idx - 1;
                up = idx + 1;
            } else {

                lb = idx - 1;
                up = idx;
            }
            while (k--) {
                if (up <= n - 1 && lb >= 0) {
                    if (arr[up] - x < x - arr[lb]) {
                        v.push_back(arr[up]);
                        up++;
                    } else {

                        v.push_back(arr[lb]);
                        lb--;
                    }
                } else if (up <= n - 1) {
                    v.push_back(arr[up]);
                    up++;
                } else {
                    v.push_back(arr[lb]);
                    lb--;
                }
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};
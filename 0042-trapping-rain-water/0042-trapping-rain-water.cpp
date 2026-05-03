class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> arr(n);
        vector<int> brr(n);
        vector<int> crr(n);
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            arr[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        maxi = -1;
        for (int i = n - 1; i >= 0; i--) {
            brr[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        for (int i = 0; i < n; i++) {
            crr[i] = min(arr[i], brr[i]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (crr[i] > height[i]) {
                sum += crr[i] - height[i];
            }
        }
        return sum;
    }
};
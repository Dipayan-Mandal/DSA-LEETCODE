class Solution {
public:
    int search(vector<int>& arr, int target) {
    int x=target;
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
    return -1;
    }
};
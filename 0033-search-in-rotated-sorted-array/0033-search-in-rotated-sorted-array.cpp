class Solution {
public:
    int bs(int lo, int hi, int x, vector<int>& arr) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == x)
                return mid;

            // If x greater, ignore left half
            else if (arr[mid] < x)
                lo = mid + 1;

            // If x is smaller, ignore right half
            else
                hi = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        if(n == 2) {
            if (target == arr[0])
                return 0;
            else if (target == arr[1])
                return 1;
            else
                return -1;
        }
            int pivot = -1;
            // 4,5,6,7,0,1,2
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (mid == 0)
                    lo = mid + 1;
                else if (mid == n - 1)
                    hi = mid - 1;
                else if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]) {
                    pivot = mid;
                    break;
                } else if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                    pivot = mid + 1;
                    break;
                } else if (arr[mid] > arr[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            if (pivot == -1)
                return bs(0, n - 1, target, arr);
            if (target >= arr[0] && target <= arr[pivot - 1])
                return bs(0, pivot - 1, target, arr);
            else
                return bs(pivot, n - 1, target, arr);
        }
    };
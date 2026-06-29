class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> v(n);
        v[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (st.size() > 0 && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (st.size() == 0) {
                v[i] = n;
            } else 
                v[i] = st.top();
                st.push(i);
        }

        int psi[n];
        stack<int> gt;
        psi[0] = -1;
        gt.push(0);
        for (int i = 1; i< n; i++) {
            while (gt.size() > 0 && arr[gt.top()] >= arr[i])
                gt.pop();
            if (gt.size() == 0)
                psi[i] = -1;
            else
                psi[i] = gt.top();
            gt.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int height = arr[i];
            int breadth = v[i] - psi[i] - 1;
            int area = height * breadth;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
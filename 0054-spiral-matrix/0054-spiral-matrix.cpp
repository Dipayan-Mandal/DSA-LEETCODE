class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minr = 0;
        int maxr = m - 1;
        int minc = 0;
        int maxc = n - 1;
        int te=m*n;
        int count=0;
        vector<int> v;
        while (minr <= maxr && minc <= maxc) {

            for (int i = minc; i <= maxc && count<te; i++) {
                v.push_back(matrix[minr][i]);
                count++;
            }
            minr++;
            for (int j = minr; j <= maxr && count<te; j++) {
                v.push_back(matrix[j][maxc]);
                count++;
            }
            maxc--;
            for (int i = maxc; i >= minc && count<te; i--) {
                v.push_back(matrix[maxr][i]);
                count++;
            }
            maxr--;
            for (int j = maxr; j >= minr && count<te; j--) {
                v.push_back(matrix[j][minc]);
                count++;
            }
            minc++;
        }
        return v;
    }
};
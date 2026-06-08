class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int minr = 0;
        int maxr = n - 1;
        int minc = 0;
        int maxc = n - 1;

        int te = n * n;
        int count = 0;
        int num = 1;

        while (minr <= maxr && minc <= maxc) {

            for (int i = minc; i <= maxc && count < te; i++) {
                matrix[minr][i] = num++;
                count++;
            }
            minr++;

            for (int j = minr; j <= maxr && count < te; j++) {
                matrix[j][maxc] = num++;
                count++;
            }
            maxc--;

            for (int i = maxc; i >= minc && count < te; i--) {
                matrix[maxr][i] = num++;
                count++;
            }
            maxr--;

            for (int j = maxr; j >= minr && count < te; j--) {
                matrix[j][minc] = num++;
                count++;
            }
            minc++;
        }

        return matrix;
    }
};
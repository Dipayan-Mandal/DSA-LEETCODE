/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> matrix(m, vector<int>(n, -1));
         int minr = 0, maxr = m - 1;
        int minc = 0, maxc = n - 1;

        ListNode* temp = head;

        while (temp && minr <= maxr && minc <= maxc) {

            for (int i = minc; i <= maxc && temp; i++) {
                matrix[minr][i] = temp->val;
                temp = temp->next;
            }
            minr++;

            for (int i = minr; i <= maxr && temp; i++) {
                matrix[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;

            if (minr <= maxr) {
                for (int i = maxc; i >= minc && temp; i--) {
                    matrix[maxr][i] = temp->val;
                    temp = temp->next;
                }
                maxr--;
            }

            if (minc <= maxc) {
                for (int i = maxr; i >= minr && temp; i--) {
                    matrix[i][minc] = temp->val;
                    temp = temp->next;
                }
                minc++;
            }
        }

        return matrix;
    }
};
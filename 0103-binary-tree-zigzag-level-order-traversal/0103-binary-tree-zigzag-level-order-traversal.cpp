/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void levelOrderTraverse(TreeNode* root, int curr, int targetLevel,
                            vector<int>& v) {
        if (root == NULL)
            return;
        if (curr == targetLevel) {
            v.push_back(root->val);
            return;
        }

        if (targetLevel % 2 != 0) {
            levelOrderTraverse(root->right, curr + 1, targetLevel, v);
            levelOrderTraverse(root->left, curr + 1, targetLevel, v);
        } else {
            levelOrderTraverse(root->left, curr + 1, targetLevel, v);
            levelOrderTraverse(root->right, curr + 1, targetLevel, v);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = levels(root);
        for (int i = 0; i < n; i++) {
            vector<int> v;
            levelOrderTraverse(root, 0, i, v);
            ans.push_back(v);
        }
        return ans;
    }
};
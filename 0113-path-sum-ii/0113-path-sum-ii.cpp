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
    void helper(vector<vector<int>>& ans, vector<int> v, TreeNode* root,
                int targetSum) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            if (root->val == targetSum) {
                v.push_back(root->val);
                ans.push_back(v);
            }
        }
        v.push_back(root->val);
        helper(ans, v, root->left, targetSum - root->val);
        helper(ans, v, root->right, targetSum - root->val);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans, v, root, targetSum);
        return ans;
    }
};
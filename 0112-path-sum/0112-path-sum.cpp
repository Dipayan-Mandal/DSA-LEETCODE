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
    void helper(TreeNode* root, int targetSum,bool &ans) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == targetSum)
                ans=true;
            return;
        }

        helper(root->left, targetSum - (root->val),ans);
        helper(root->right, targetSum - (root->val),ans);
       
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;
         bool ans = false;
        helper(root, targetSum,ans);
        return ans;
    }
};
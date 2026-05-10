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
    /*int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }*/
    void preorder(TreeNode* root,int n,vector<int> &ans)
    {
        if(root==NULL) return;
        if(n==ans.size()) ans.push_back(root->val);
        preorder(root->right,n+1,ans);
        preorder(root->left,n+1,ans);
    }
    

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        
        preorder(root,0,ans);
        return ans;
    }
};
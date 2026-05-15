
class Solution {
public:
    void helper(TreeNode* dummy, int lo, int hi)
    {
        if(dummy==NULL) return;
        while(dummy->left!=NULL)
        {
            if(dummy->left->val<lo)
            dummy->left=dummy->left->right;
            else if(dummy->left->val>hi)  dummy->left=dummy->left->left;
            else break;
        }
         while(dummy->right!=NULL)
        {
            if(dummy->right->val>hi)
            dummy->right=dummy->right->left;
            else if(dummy->right->val<lo)  dummy->right=dummy->right->right;
            else break;
        }
        helper(dummy->left,lo,hi);
        helper(dummy->right,lo,hi);

    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        helper(dummy,low,high);
        return dummy->left;
    }
};
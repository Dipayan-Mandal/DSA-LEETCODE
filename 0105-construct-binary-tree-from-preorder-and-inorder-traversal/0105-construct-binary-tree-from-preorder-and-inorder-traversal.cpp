/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* helper(vector<int>& pre,int prel,int prehi,vector<int>& in,int inl,int inh)
    {
        if(prel>prehi) return NULL;

        TreeNode* root=new TreeNode(pre[prel]);
        if(prel==prehi) return root;
        int i=0;
        while(i<=inh)
        {
            if(pre[prel]==in[i]) break;
            i++;
        }
        int left=i-inl;
        int right=inh-(i+1);
        root->left=helper(pre,prel+1,prel+left,in,inl,i-1);
        root->right=helper(pre,prel+left+1,prehi,in,i+1,inh);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        return helper(pre,0,n-1,in,0,n-1);
        
    }
};
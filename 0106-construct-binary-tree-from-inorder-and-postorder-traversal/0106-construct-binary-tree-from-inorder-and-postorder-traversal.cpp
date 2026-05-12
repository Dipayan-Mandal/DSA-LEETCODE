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

    TreeNode* helper(vector<int>& in,int inl,int inh, vector<int>& post,int postl,int posth)
    {
        if(postl>posth) return NULL;
        
        TreeNode* root=new TreeNode(post[posth]);
        if(postl==posth) return root;
        int i=0;
        while(i<=inh)
        {
            if(post[posth]==in[i]) break;
            i++;      
        }
        int left=i-inl;
        int right=inh-(i+1);
        root->left=helper(in,inl,i-1,post,postl,postl+left-1);
        root->right=helper(in,i+1,inh,post,postl+left,posth-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        return helper(in,0,n-1,post,0,n-1);
    }
};
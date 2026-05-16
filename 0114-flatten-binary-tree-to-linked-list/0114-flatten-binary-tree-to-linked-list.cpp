
class Solution {
public:
    void preorder(TreeNode* root,vector<TreeNode*> &ans)
    {
        if(root==NULL) return;
        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right,ans);
      
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        
        preorder(root,ans);
        
        for(int i=0;i+1<ans.size();i++) //When ans.size() == 0, this becomes:0 - 1
        {
            ans[i]->right=ans[i+1];
            ans[i]->left=NULL;
        }
        if(!ans.empty())
        {
            ans.back()->left = NULL;
            ans.back()->right = NULL;
        }
    }
};
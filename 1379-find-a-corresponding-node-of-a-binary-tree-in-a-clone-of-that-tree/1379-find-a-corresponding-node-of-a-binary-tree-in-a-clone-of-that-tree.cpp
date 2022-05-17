class Solution {
public:
    void helper(TreeNode* &root, int &key, TreeNode* &ans){
        if(root!=NULL){
            helper(root->left, key, ans);
            if(root->val==key){
                ans = root;
            }
            helper(root->right, key, ans);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        helper(cloned, target->val, ans);
        return ans;
    }
};
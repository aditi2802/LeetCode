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
    int minDiffInBST(TreeNode* root) {
        vector<int>dfs;
        inorder(root, dfs);
        int mini = INT_MAX;
        
        for(int i=1;i<dfs.size();i++){
            mini = min(mini,dfs[i]-dfs[i-1]);
        }
        return mini;
    }
    
    void inorder(TreeNode* root, vector<int>& dfs){
        if(root==NULL) return;
        inorder(root->left, dfs);
        dfs.push_back(root->val);
        inorder(root->right, dfs);
    }
};
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
    int minDepth(TreeNode* root) {
        int ans;
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1; //leaf node
        
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        
        if(root->left==NULL) return 1 + rh;
        if(root->right==NULL) return 1 + lh;
        
        return 1+min(lh,rh);
    }
};
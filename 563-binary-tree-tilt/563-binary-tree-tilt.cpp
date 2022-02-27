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
    int sum = 0;
    int findTilt(TreeNode* root) {
        helper(root);
        return sum;
    }
    
    int helper(TreeNode* root){
       if(!root) return 0;
        
        int lsum = helper(root->left);
        int rsum = helper(root->right);
        sum += abs(lsum-rsum);
        
        return lsum + rsum + root->val;
    }
};
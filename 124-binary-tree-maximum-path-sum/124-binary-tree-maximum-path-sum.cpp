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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
    
    int maxPath(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }
        
        int lh = maxPath(root->left, maxi);
        int rh = maxPath(root->right, maxi);
        
        if(lh<0) lh = 0;   //taking -ve path will never give max path sum so ignore all
        if(rh<0) rh = 0;   // -ve paths coming from left and right and set them to 0
        
        maxi = max(root->val+lh+rh, maxi);
        return root->val+max(lh, rh);
}
};
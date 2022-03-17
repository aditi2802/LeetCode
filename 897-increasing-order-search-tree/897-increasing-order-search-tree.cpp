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
    TreeNode* ptr = new TreeNode(0);  //for traversal
    TreeNode* ans = ptr;              //main head
    
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        return ans->right;
    }
    
    void dfs(TreeNode* root){
        if(root==NULL) return;
        
        dfs(root->left);
        ptr->right = new TreeNode(root->val);  //create node
        ptr = ptr->right;  
        dfs(root->right);
    }
};
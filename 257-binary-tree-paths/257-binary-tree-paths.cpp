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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        return helper(ans, root, "");
    }
    
    vector<string> helper(vector<string>&ans, TreeNode* root, string s){
        if(root==NULL) return ans;
        if(root->left==NULL && root->right==NULL) ans.push_back(s+to_string(root->val));
        
        helper(ans, root->left, s+to_string(root->val)+"->");
        helper(ans, root->right, s+to_string(root->val)+"->");
        return ans;
  }
};
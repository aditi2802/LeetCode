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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return balance(v, 0, v.size()-1);
    }
    
    void inorder(TreeNode* root, vector<int>&v){
       if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    TreeNode* balance(vector<int>&v, int s, int e){
        if(s>e) return NULL;
        int m = (s+e)/2;
        TreeNode* temp = new TreeNode(v[m]);
        temp->left = balance(v, s, m-1);
        temp->right = balance(v, m+1, e);
        return temp;
    }
};
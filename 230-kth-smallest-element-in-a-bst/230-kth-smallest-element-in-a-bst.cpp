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
public:                                    //inorder traversal gives sorted output of bst
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return v[k-1];
    }      
    vector<int>v;
    
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};

/*
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        preorder(root);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
    vector<int> ans;
    void preorder(TreeNode* root){
        if(root==NULL) return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};
*/
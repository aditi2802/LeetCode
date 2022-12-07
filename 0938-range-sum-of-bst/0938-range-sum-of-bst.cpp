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
class Solution {       //Recursive
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root, low, high);
        return sum;
    }
    
    void helper(TreeNode* root, int low, int high){
        if(root==NULL) return;
        if(root->val>=low && root->val<=high) sum += root->val;
        if(root->val>low) helper(root->left, low, high);
        if(root->val<high) helper(root->right, low, high);
    }
};


/* Inorder traversal method

class Solution {
public:
    vector<int> v;
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);
        for(int i=0;i<v.size();i++){
            if(v[i]>=low && v[i]<=high){
                sum += v[i];
            }
        }
        return sum;
    }
    
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};
*/
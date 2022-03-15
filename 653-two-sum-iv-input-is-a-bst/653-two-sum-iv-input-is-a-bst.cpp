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
    vector<int>v;
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        inorder(root);
        int i = 0;
        int j = v.size()-1;
        while(i<j){
            if(v[i]+v[j]>k) j--;
            else if(v[i]+v[j]<k) i++;
            else return true;
        }
        return false;
    }
    
    void inorder(TreeNode* root){
       if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};


/* Brute force
calculate the inorder traversal of the BST as it will always give sorted value
and then store all the elements in the vector
then using two pointers approach we'll find whether the value exist or not.


class Solution {
public:
    vector<int>v;
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        inorder(root);
        int i = 0;
        int j = v.size()-1;
        while(i<j){
            if(v[i]+v[j]>k) j--;
            else if(v[i]+v[j]<k) i++;
            else return true;
        }
        return false;
    }
    
    void inorder(TreeNode* root){
       if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};
*/
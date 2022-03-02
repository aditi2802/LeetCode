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
    int count = 0;
    int countNodes(TreeNode* root) {
        return inorder(root);
    }
    
    int inorder(TreeNode* root){
      if(!root) return 0;
        count++;
        inorder(root->left);
        inorder(root->right);
        return count;
    }
};



/*    O(N) TC

class Solution {
public:
    int count = 0;
    int countNodes(TreeNode* root) {
        return inorder(root);
    }
    
    int inorder(TreeNode* root){
      if(!root) return 0;
        count++;
        inorder(root->left);
        inorder(root->right);
        return count;
    }
};

*/
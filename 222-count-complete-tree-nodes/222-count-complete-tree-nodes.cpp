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
    int countNodes(TreeNode* root){
        if(!root) return 0;
        int lh = 0, rh = 0;
        
        for(TreeNode* curr=root;curr!=NULL;curr=curr->left) lh++;
        for(TreeNode* curr=root;curr!=NULL;curr=curr->right) rh++;
        
        if(lh==rh) {
            return pow(2, lh)-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
        
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
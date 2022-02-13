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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
            
            TreeNode* tmp = curr->left;  //to reverse
            curr->left = curr->right;
            curr->right = tmp;
        }
        return root;
    }
};



//     Recursive 
//  class Solution {
//  public:
//      TreeNode* invertTree(TreeNode* root) {
 //       if(root==NULL){
//           return root;
 //        }
//         else{
 //          invertTree(root->left);
 //          invertTree(root->right);
  //         swap(root->left,root->right);
  //          return root;
  //             }
   //          }
//}; 
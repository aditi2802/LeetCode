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
    int sumRootToLeaf(TreeNode* root, int sum=0) {
        if(!root) return 0;
        sum = 2*sum + root->val;  //left shift
        if(!root->left && !root->right){
            return sum;
        }
        int left = sumRootToLeaf(root->left, sum);
        int right = sumRootToLeaf(root->right, sum);
        return left + right;
    }
};
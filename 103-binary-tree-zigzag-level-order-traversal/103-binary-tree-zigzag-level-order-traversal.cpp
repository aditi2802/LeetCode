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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool LR = true;
        
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int index;
            int size = q.size();
            vector<int> innerArray(size);
            
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(LR){
                  index = i;
                }
                else{
                    index = size-1-i;
                }
                innerArray[index] = curr->val;
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            LR = !LR;
            ans.push_back(innerArray);
        }
        return ans;
    }
};
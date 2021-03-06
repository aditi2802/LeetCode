/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if(root==NULL){
            return ans;
        }
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> innerArray;
            
            for(int i=0;i<size;i++){
                Node* curr = q.front();
                q.pop();
                innerArray.push_back(curr->val);
                
                for(int j=0;j<curr->children.size();j++){
                    q.push(curr->children[j]);
                }
            }
            ans.push_back(innerArray);
        }
        return ans;
    }
};
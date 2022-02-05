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
private :
    void dfs(Node* node, vector<int> &ans){
        if(node==NULL){
          return;
        }
        for(int i=0;i<node->children.size();i++){
          dfs(node->children[i], ans);
        }
        ans.push_back(node->val);
    }
    
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
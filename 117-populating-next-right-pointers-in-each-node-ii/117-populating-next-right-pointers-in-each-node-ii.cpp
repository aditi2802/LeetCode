/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node* root){
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* curr = q.front();
                q.pop();
                
                if(curr==NULL){
                    q.push(NULL);
                    continue;
                }
                else{
                    curr->next = q.front();
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
    
    Node* connect(Node* root) {
        if(!root) return NULL;
        helper(root);
        return root;
    }
};
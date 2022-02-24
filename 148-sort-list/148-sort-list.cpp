/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL ||head->next==NULL) return head;
        
        vector<int> v;
        for(ListNode*curr=head;curr!=NULL;curr=curr->next){
           v.push_back(curr->val);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        for(ListNode*curr=head;curr!=NULL;curr=curr->next){
           curr->val = v.back();
            v.pop_back();
        }
        return head;
    }
};
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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* s, ListNode* e){
        if(s==NULL) return e;
        if(e==NULL) return s;
        
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        
        while(s!=NULL && e!=NULL){
            if(s->val<e->val){
                curr->next = s;
                curr = s;
                s = s->next;
            }
            else{
                curr->next = e;
                curr = e;
                e = e->next;
            }
        }
        while(s!=NULL){
            curr->next = s;
            curr = s;
            s = s->next;
        }
        while(e!=NULL){
            curr->next = e;
            curr = e;
            e = e->next;
        }
        ans = ans->next;
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = findMid(head);
        ListNode* s = head;
        ListNode* e = mid->next;
        mid->next = NULL;
        
        s = sortList(s);
        e = sortList(e);
        ListNode* res = merge(s, e);
        return res;
    }
};
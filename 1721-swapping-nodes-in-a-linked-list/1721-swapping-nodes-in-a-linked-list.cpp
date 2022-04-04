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
    int helper(ListNode* head){
       int len = 0;
        while(head!=NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int len = helper(head);
        
        ListNode* start = head;
        for(int i=0;i<k-1;i++){
          start = start->next;
        }
        ListNode* end = head;
        for(int i=0;i<len-k;i++){
           end = end->next;
        }
        swap(start->val, end->val);
        return head;
    }
};
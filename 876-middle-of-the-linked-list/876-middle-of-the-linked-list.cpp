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
    ListNode* middleNode(ListNode* head) {     //approach is when fast reaches end slow 
        ListNode* slow = head;                  //will be at middle
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};







/*Brute force
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        
        for(ListNode*curr=head;curr!=NULL;curr=curr->next){
            count++;
        }
        
        for(int i=0;i<count/2;i++){
            head = head->next;
        }
        return head;
    }
};

*/
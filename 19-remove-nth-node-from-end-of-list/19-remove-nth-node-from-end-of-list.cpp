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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* ans=head;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        head=ans;
        int diff=len-n;
        if(n>len){
            return head;
        }
        else if(len==n){
            return head->next;
        }
        else{
            ListNode* prev=NULL;
            for(int i=0;i<diff;i++){
                prev=ans;
                ans=ans->next;
            }
            prev->next=ans->next;
        }
        return head;
    }
};
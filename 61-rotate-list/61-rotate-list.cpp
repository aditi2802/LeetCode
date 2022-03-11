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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* curr = head;
        int len = 1;
        while(curr->next!=NULL){
            len++;               //step 1
            curr = curr->next;
        }
        curr->next = head;  //step 2
        k = k%len;   
        for(int i=0;i<len-k;i++){
            curr = curr->next;   
        }
        head = curr->next; //step 4
        curr->next = NULL;  //step 3
        return head;
    }
};


/*
Steps : (Example 1)
1. Count length of L.L.      //5
2. Point last node's next to head (Make it circular L.L).   //5 to 1
3. Point (length - k)th node to null. //3 to null
4. Point 4 to head
*/
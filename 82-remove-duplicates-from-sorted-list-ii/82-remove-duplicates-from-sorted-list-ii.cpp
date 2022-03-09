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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return 0;
        if(!head->next) return head;
        
        int value = head->val;
        ListNode* temp = head->next;  		// temp contain the reference of next node
        
        if(temp->val!=value){              //if the next node have different value then   
            head->next = deleteDuplicates(temp);  // update head->next by temp
            return head; 
        }
        else{                                          // if the values are same    
            while(temp!=NULL && temp->val == value){   //just update temp to temp->next;
                ListNode* p = temp;
                temp = temp->next;
                delete p;
            }
            return deleteDuplicates(temp);    				// freeing the memory
        }
    }
};
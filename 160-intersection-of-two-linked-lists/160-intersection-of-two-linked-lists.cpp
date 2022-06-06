/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* node){
        int cnt=1;
        while(node!=NULL){
            node=node->next;
            cnt++;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=len(headA),m=len(headB);                  //Step1
        if(m>n){
            swap(headA,headB);
            swap(n,m);
        }
        int d=n-m;                           //Step1
        for(int i=0;i<d;++i)headA=headA->next;                          //step2
        while(headA!=NULL || headB!=NULL){
            if(headA==headB)return headA;
            headA=headA->next;                                                     //step3
            headB=headB->next;
        }
        return NULL;

    }
};
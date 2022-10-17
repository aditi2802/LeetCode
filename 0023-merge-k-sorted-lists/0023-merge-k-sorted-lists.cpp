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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        for(int i=0;i<lists.size();i++){
            ListNode* p = lists[i];
            while(p!=NULL){
                pq.push(p->val);
                p = p->next;
            }
        }
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        return ans->next;
    }
};
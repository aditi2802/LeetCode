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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};



/*
Input: 1->2->3->4->5->6
node = 4
output: 1->2->3->5->6


1. in first step: node->val becomes node's next ki value i.e 4 becomes 5
1->2->3->5->5->6
2. in 2nd step: node points to node's next next i.e 5->6
1->2->3->5->6


*/
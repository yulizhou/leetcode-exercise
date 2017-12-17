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
    ListNode* swapPairs(ListNode* head) {
        ListNode *copy = new ListNode(-1);
        ListNode *cur = copy;
        copy->next = head;
        while (cur->next && cur->next->next) {
            ListNode *t = cur->next->next;
            cur->next->next = t->next;
            t->next = cur->next;
            cur->next = t;
            cur = t->next;
        }
        return copy->next;
    }
};
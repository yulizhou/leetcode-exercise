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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = 1; // record the length
        ListNode* cur = head;
        // loop over the list
        while (cur->next) {
            len++;
            cur = cur->next;
        }
        cur->next = head; // make the loop
        for (int i = 0; i < len - k % len; i++) {
            cur = cur->next;
        }
        ListNode* res = cur->next;
        cur->next = NULL;
        return res;
    }
};
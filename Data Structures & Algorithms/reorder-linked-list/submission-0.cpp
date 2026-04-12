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
    void reorderList(ListNode* head) {
        if (!head->next)
            return;

        ListNode *slow = head;
        for (ListNode *fast = head->next; fast && fast->next; ) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* half = slow->next;
        slow->next = nullptr;

        // reverse linked list
        ListNode *rev = nullptr;
        while (half) {
            ListNode *tmp = half;
            half = half->next;
            tmp->next = rev;
            rev = tmp;
        }

        // add to current linked list
        for (ListNode *p = head; p && rev; ) {
            ListNode *tmp = p->next;
            p->next = rev;
            rev = rev->next;
            p->next->next = tmp;
            p = tmp;
        } 
    }
};

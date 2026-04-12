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
    bool hasCycle(ListNode* head) {
        ListNode *first = head->next;
        ListNode *second;
        if (head->next)
            second = head->next->next;
        else
            return false;

        while (first && second) {
            if (first == second)
                return true;
            first = first->next;
            if (second->next)
                second = second->next->next;
            else
                return false;
        }

        return false;
    }
};

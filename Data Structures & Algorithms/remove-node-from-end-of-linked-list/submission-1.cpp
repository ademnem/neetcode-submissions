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
        vector<ListNode*> nodes;
        int size = 0;
        for (ListNode* p = head; p; p = p->next, ++size)
            nodes.push_back(p);
        if (size - n - 1 < 0)
            return head->next;
        ListNode *prev = nodes[size - n - 1];
        ListNode *curr = nodes[size - n];
        prev->next = curr->next;
        return head;
    }
};

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
        ListNode res{0, nullptr};
        ListNode* p = &res;
        int len = lists.size(); 

        while (true) {
            bool nodesRemaining = false;
            ListNode** lowest = nullptr;
            for (int i = 0; i < len; ++i) {
                if (lists[i] && (!lowest || lists[i]->val < (*lowest)->val)) {
                    nodesRemaining = true;
                    lowest = &lists[i];
                }
            }

            if (!nodesRemaining) {
               p->next = nullptr; 
               return res.next;
            }

            ListNode* tmp = *lowest;
            *lowest = (*lowest)->next;
            p->next = tmp;
            p = p->next;
        } 
    }
};

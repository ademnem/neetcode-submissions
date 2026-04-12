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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = nullptr; // create new LL

        if (!list1 && list2)
            return list2;
        else if (list1 && !list2)
            return list1;
        else if (!list1 && !list2)
            return nullptr;
        
        // adding first node to merged list
        if (list1->val < list2->val) {
            newList = list1;
            list1 = list1->next;
        } else {
            newList = list2;
            list2 = list2->next;
        }

        // interleave list values
        ListNode* p = newList;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else { // L1 >= L2
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        
        // appending remaining list values
        if (!list1) {
            p->next = list2;
        } else {
            p->next = list1; 
        } 

        return newList;
    }
};

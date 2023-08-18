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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode *head = result;
        int excess = 0;

        while (l1 != NULL || l2 != NULL || excess > 0){
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;
            
            int value = val1 + val2 + excess;
            
            if (value >= 10){
                excess = 1;
                value = value - 10;
            } else {
                excess = 0;
            }
            ListNode *temp = new ListNode(value);
            
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }

            result->next = temp;
            result = result->next;
        }
        return head->next;
    }
};
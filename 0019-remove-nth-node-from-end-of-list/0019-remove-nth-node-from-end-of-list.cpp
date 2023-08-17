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
        if (head->next == NULL){
            return NULL;
        }
        ListNode *cnt = head;
        int no = 1;
        while (cnt->next != NULL){
            cnt = cnt->next;
            no++;
        }
        
        if (n == no){
            head = head->next;
            return head;
        }

        ListNode *curr = head;
        int count = 1;
        while (count < no - n){
            curr = curr->next;
            count++;
        }
        curr->next = curr->next->next;
        return head;
    }
};
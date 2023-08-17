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
        if (head->next == NULL) {
            return;
        }
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverseLinkedList(slow);
        mergeLinkedLists(head, slow);
    }
private:
    ListNode* reverseLinkedList(ListNode *head){
        ListNode *prev = NULL, *current = head, *nxt = NULL;
        while (current != NULL){
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }
    void mergeLinkedLists(ListNode* l1, ListNode* l2){
        while (l1 != NULL){
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            l1->next = l2;
            if (temp1 == NULL){
                break;
            }
            l2->next = temp1;

            l1 = temp1;
            l2 = temp2;
        }
    }
};
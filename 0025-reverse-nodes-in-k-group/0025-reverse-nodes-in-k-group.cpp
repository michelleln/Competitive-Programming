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
 //the neetcode way but apparently doesn't work in c++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        ListNode* result = new ListNode();
        result->next = head;

        ListNode *prev = result;
        ListNode *curr = result->next;
        ListNode *temp = NULL;
        //int count = k;

        while (curr != NULL){
            for (int i = 0; i < k - 1; i++){
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                //count--;
            } //else {
                prev = curr;
                curr = curr->next;
                //count = k;
                
                ListNode *end = curr;
                //i < k - 1 runtime error while i < k works
                for (int i = 0; i < k; i++){
                    if (end == NULL){
                        return result->next;
                    }
                    end = end->next;
                }
            //}
        }
        return result->next;
    }
};
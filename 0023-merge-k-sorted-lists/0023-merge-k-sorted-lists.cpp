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
        //ListNode* temp = new ListNode();
        if (lists.size() == 0 || lists.empty()){
            return NULL;
        }
        for (int i = 0; i < lists.size() - 1; i++){
            if (lists[i] == NULL) {
                continue;
            }
            ListNode *first = lists[i];
            ListNode *second = lists[i + 1];
            ListNode* temp = new ListNode();
            ListNode *curr = temp;
            
            while (first != NULL && second != NULL){
                if (first->val < second->val){
                    curr->next = first;
                    first = first->next;
                } else {
                    curr->next = second;
                    second = second->next;
                }
                curr = curr->next;
            }
            if (first == NULL){
                curr->next = second;
            }
            if (second == NULL){
                curr->next = first;
            }
            
            lists[i + 1] = temp->next;
        }
        return lists[lists.size() - 1];
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node *curr = head;
        while (curr != NULL){
            nodes[curr] = new Node (curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != NULL){
            nodes[curr]->next = nodes[curr->next];
            nodes[curr]->random = nodes[curr->random];
            curr = curr->next;
        }
        return nodes[head];
    }
};
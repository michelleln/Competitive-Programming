class Node {
public:
    int k;
    int val;
    Node* next;
    Node* prev;

    Node (int key, int value){
        k = key;
        val = value;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            remove(cache[key]);
            delete cache[key];
        } 
        cache[key] = new Node(key, value);
        insert(cache[key]);
        if (cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);

            // Free allocated memory for the removed node
            delete lru;
        }
    }
private:
    unordered_map<int, Node*> cache;
    int cap;
    Node *left;
    Node *right;

    void remove (Node* node){
        Node *next = node->next;
        Node *prev = node->prev;
        prev->next = next;
        next->prev = prev;
    }
    //insert node at right so that least recently used can be the first int helinked list and can be evicted right away
    void insert (Node* node){
        Node* before = right->prev;
        Node* after = right;

        before->next = node;
        node->prev = before;

        node->next = after;
        after->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
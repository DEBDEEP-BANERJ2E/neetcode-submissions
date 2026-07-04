class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* node = cache[key];
        
        // Inline Remove
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        // Inline Insert at Tail
        Node* prevNode = tail->prev;
        prevNode->next = node;
        tail->prev = node;
        node->prev = prevNode;
        node->next = tail;
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            
            // Inline Remove
            node->prev->next = node->next;
            node->next->prev = node->prev;
            
            // Inline Insert at Tail
            Node* prevNode = tail->prev;
            prevNode->next = node;
            tail->prev = node;
            node->prev = prevNode;
            node->next = tail;
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            
            // Inline Insert at Tail
            Node* prevNode = tail->prev;
            prevNode->next = newNode;
            tail->prev = newNode;
            newNode->prev = prevNode;
            newNode->next = tail;
            
            // Inline Eviction Logic
            if (cache.size() > capacity) {
                Node* lru = head->next;
                
                head->next = lru->next;
                lru->next->prev = head;
                
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
    
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

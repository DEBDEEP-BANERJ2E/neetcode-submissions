class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    
    // Dummy head and tail nodes to avoid null pointer checks during list manipulations
    Node* head;
    Node* tail;

    // Helper to remove a node from its current position in the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper to insert a node at the rightmost position (just before tail) as the MRU
    void insert(Node* node) {
        Node* prevNode = tail->prev;
        
        prevNode->next = node;
        tail->prev = node;
        
        node->prev = prevNode;
        node->next = tail;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node); // Move to the tail (MRU)
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists: update its value and refresh its position to MRU
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
        } else {
            // Key doesn't exist: create a new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(newNode);
            
            // Check if capacity is exceeded
            if (cache.size() > capacity) {
                // Remove the LRU node (just after head)
                Node* lru = head->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru; // Clean up memory
            }
        }
    }
    
    // Destructor to prevent memory leaks
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

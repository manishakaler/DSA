class LRUCache {
   private:
    struct ListNode {
        int key, val;
        ListNode* next;
        ListNode* prev;
        ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {};
        ListNode(int k, int v, ListNode* n, ListNode* p) : key(k), val(v), next(n), prev(p) {};
    };

    int capacity;
    unordered_map<int, ListNode*> cacheMap;
    ListNode* head = new ListNode(0,0);
    ListNode* tail = new ListNode(0,0);

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void bringToEnd(ListNode* curr) {
        // detach
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        // add to end -- p-c-t
        curr->prev = tail->prev;
        curr->next = tail;
        tail->prev->next = curr;
        tail->prev = curr;
    }

    void removeFromFront() {
        ListNode* lru = head->next;
        cacheMap.erase(lru->key);
        head->next = lru->next;
        lru->next->prev = head;
        delete (lru);
    }

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            ListNode* curr = cacheMap[key];
            bringToEnd(curr);
            return curr->val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            ListNode* curr = cacheMap[key];
            curr->val = value;
            cacheMap[key] = curr;
            bringToEnd(curr);
            return;
        }

        if (cacheMap.size() == capacity) {
            removeFromFront();
        }
        ListNode* newNode = new ListNode(key, value);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
      
        cacheMap[key] = newNode;
    }
};

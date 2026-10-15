#include<list> //no semicolon needed

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){};
    };

    int capacity;
    unordered_map<int,Node*>cacheMap;
    Node* head; //dummy head
    Node* tail; //dummy tail

    // functions needed - move-to-end on get, delete from front, insert at end
    void moveToEnd(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        insertAtEnd(node);
    }

    void insertAtEnd(Node* node){
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    void evictFromFront(){
        Node* node = head->next;
        head->next = node->next;
        head->next->prev = head;
        cacheMap.erase(node->key);
        delete(node);
    }



public:
    LRUCache(int capacity) {
       head = new Node(-1,-1);
       tail = new Node(-1,-1);
       head->next = tail;
       tail->prev = head;
       this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key)!=cacheMap.end()){
            Node* node = cacheMap[key];
            moveToEnd(node);
            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        //case 1 - size>cap, eviction required, case 2- key found - update? - case 3- new insert
        if(cacheMap.find(key)!=cacheMap.end()){
            Node* curr = cacheMap[key];
            curr->value = value;
            moveToEnd(curr);
            return;
        }

        if(cacheMap.size() >= capacity){
            evictFromFront();
        }

        Node* newNode = new Node(key,value);
        cacheMap[key] = newNode;
        insertAtEnd(newNode);
    }
};

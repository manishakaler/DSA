class RandomizedSet {
    unordered_map<int,int>rset;
    int size;
public:
    RandomizedSet() {
        this->size = 0;
    }
    
    bool insert(int val) {
        if(rset.find(val) == rset.end()){
            rset[val]=1;
            size++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(rset.count(val)){
            rset.erase(val);
            size--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int cap = rset.size();
        int idx = rand() % cap;
        auto it = rset.begin();
        advance(it,idx);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
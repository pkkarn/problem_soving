struct Cache {
    int key;
    int priority;
    Cache(int val) {
        this->key = val;
        this->priority = 1;
    };
};

class LFUCache {
public:
    int capacity;
    vector<Cache*> removeList; // Min heap to remove least recently used
    map<int, pair<int, int>> use_counter; // To perform pair<int(value), int(priority)>

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(use_counter.count(key)) {
            use_counter[key].second += 1;
            for(auto i: use_counter) {
                if(i.first != key) {
                    use_counter[i.first].second -= 1;
                }
            }
            return use_counter[key].first;
        } else {
            return -1;
        }  
        return use_counter[key].first;
    }
    
    void put(int key, int value) {
        if(capacity) {
            // If its less than capacity and key doesn't exist;
            if(use_counter.count(key)) {
                use_counter[key].second += 1;
                use_counter[key].first = value;
            } else {
                if(use_counter.size() >= this->capacity) {
                    int low = INT_MAX;
                    int lowKey;

                    for(auto i: use_counter) {
                        if(i.second.second < low) {
                            low = i.second.second;
                            lowKey = i.first;
                        }
                    }

                    use_counter.erase(lowKey);
                    use_counter[key].second += 1;
                    use_counter[key].first = value;
                } else {
                    use_counter[key].second += 1;
                    use_counter[key].first = value;
                }
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

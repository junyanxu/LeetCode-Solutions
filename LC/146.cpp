class LRUCache{
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if(data.count(key)){
            pair<int, int> res = *data[key];
            LRU.erase(data[key]);
            LRU.push_front(res);
            data[key] = LRU.begin();
            return res.second;
        }
        else{
            return -1;
        }
    }

    void set(int key, int value) {
        if(data.count(key)){
            LRU.erase(data[key]);
            LRU.push_front(make_pair(key, value));
            data[key] = LRU.begin();
        }
        elseflag
            if(LRU.size() == this->cap) {
                data.erase(LRU.back().first);
                LRU.pop_back();
            }
            LRU.push_front(make_pair(key, value));
            data[key] = LRU.begin();
        }
    }

private:
    int cap;
    list<pair<int, int>> LRU;
    unordered_map<int, list<pair<int, int>>::iterator> data;

};

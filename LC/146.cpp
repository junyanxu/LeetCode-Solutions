class LRUCache{
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if(!kp.count(key)){return -1;}
        else{
            pair<int, int> temp = *kp[key];
            data.erase(kp[key]);
            data.push_front(temp);
            kp[key] = data.begin();
            return temp.second;
        }
    }

    void set(int key, int value) {
        if(kp.count(key)){
            pair<int, int> temp = *kp[key];
            temp.second = value;
            data.erase(kp[key]);
            data.push_front(temp);
            kp[key] = data.begin();
        }
        else{
            if(data.size() < this->cap){
                data.push_front(make_pair(key, value));
                kp[key] = data.begin();
            }
            else{
                kp.erase(data.back().first);
                data.pop_back();
                data.push_front(make_pair(key, value));
                kp[key] = data.begin();
            }
        }
    }
private:
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator> kp;
    list<pair<int, int>> data;
};

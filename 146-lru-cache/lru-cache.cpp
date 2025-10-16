class LRUCache {
    list<int> l;
    unordered_map<int,pair<int,int>> mp;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        mp[key].second++;
        l.push_back(key);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            it->second.first=value;
            l.push_back(it->first);
            it->second.second++;
            return;
        }
        
        if(mp.size()<capacity){
            mp[key]={value,1};
            l.push_back(key);
            return;
        }

        // overflow

        while(mp[l.front()].second>1){
            mp[l.front()].second--;
            l.pop_front();
        }

        int lowkey=l.front();
        mp.erase(lowkey);
        l.pop_front();
        l.push_back(key);
        mp[key]={value,1};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
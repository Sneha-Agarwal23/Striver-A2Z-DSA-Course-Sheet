class LRUCache {
    int cachesize;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> m; 
public:
    LRUCache(int capacity)
    {
        cachesize = capacity;   
    }
    
    int get(int key) 
    {
        if(m.find(key) != m.end())
        {
            auto it = m[key];
            int value = it->second;
            cache.erase(it);
            cache.push_front({key,value});
            m[key] = cache.begin();
            return value;
        }
        else
            return -1;    
    }
    
    void put(int key, int value) 
    {
        if(m.find(key) == m.end())
        {
            if(cache.size() == cachesize)
            {
                pair<int,int> lru = cache.back();
                cache.pop_back();
                m.erase(lru.first);
            }
        }
        else
        {
            cache.erase(m[key]);
        }
        cache.push_front({key,value});
        m[key] = cache.begin();    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
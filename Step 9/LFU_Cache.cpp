class LFUCache {
    int cap, minFreq;
    unordered_map<int, pair<int,int>> keyValFreq;
    unordered_map<int, list<int>> freqKey;
    unordered_map<int, list<int> :: iterator> keyItr;
public:
    LFUCache(int capacity)
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if(keyValFreq.find(key) == keyValFreq.end())
        {
            return -1;
        }
        int f = keyValFreq[key].second;
        freqKey[f].erase(keyItr[key]);
        f++;
        freqKey[f].emplace_front(key);
        keyItr[key] = freqKey[f].begin();
        keyValFreq[key].second = f;
        
        if(freqKey[minFreq].empty())
            minFreq = f;
        return keyValFreq[key].first;
    }
    
    void put(int key, int value) 
    {
        if(cap <= 0)
            return;
        if(get(key) != -1)
        {
            keyValFreq[key].first = value;
            return;
        }
        if(keyValFreq.size() == cap)
        {
            int del = freqKey[minFreq].back();
            freqKey[minFreq].pop_back();
            keyValFreq.erase(del);
            keyItr.erase(del);
        }
        minFreq = 1;
        keyValFreq[key] = {value,minFreq};
        freqKey[minFreq].emplace_front(key);
        keyItr[key] = freqKey[minFreq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
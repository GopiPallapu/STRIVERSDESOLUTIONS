class MyHashMap {
public:
    vector<list<pair<int,int>>> mp;
    int size;
    MyHashMap() {
        size = 100;
        mp.resize(size);
    }
    // same as hashet , hash function
    int hash(int key)
    {
        return key%size;
    }
    list<pair<int,int>> :: iterator search(int key)
    {
        int i = hash(key);
        list<pair<int,int>> :: iterator itr =mp[i].begin();
        while(itr != mp[i].end())
        {
            if(itr->first == key)return itr;
            itr++;
        }
        return itr;

    }

    void put(int key, int value)
    {
        int i = hash(key);
        remove(key);
        mp[i].push_back({key,value});
    }
    
    int get(int key)
    {
        int i = hash(key);
        list<pair<int,int>> :: iterator itr1 = search(key);
        if(itr1 != mp[i].end())
        {
            return itr1->second;
        }
        return -1;
    }
    
    void remove(int key) 
    {
        int i = hash(key);
        if(search(key) != mp[i].end())
            mp[i].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
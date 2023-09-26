class RandomizedSet {
public:
    vector<int> m ;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false ;
        m.push_back(val) ;
        mp.insert({val,m.size()-1});
        return true ;
    }
    
    bool remove(int val) {
        if(mp.find(val)== mp.end()) return false ;
        int index = mp[val] ;
        int v = m.back() ;
        m[index] = v ;
        mp[v] = index ;
        mp.erase(val) ;
        m.pop_back() ;
        return true ;
    }
    
    int getRandom() {
        return m[rand()%m.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
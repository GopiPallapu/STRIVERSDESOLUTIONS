
class RandomizedSet {
public:
    vector<int> v ;
    unordered_map<int,int> map;
    RandomizedSet() {
        v.clear() ;
        map.clear() ;
    }
    
    bool insert(int val) {
        if(map.find(val) != map.end())
            return false ;
        map[val] = v.size() ;
        v.push_back(val);
        return true ;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end())
            return false ;
        int index = map[val] ;
        int lastVal = v.back() ;
        map[lastVal] = index ;
        v[index] = lastVal ;
        map.erase(val);
        v.pop_back() ;
        return true;
    }
    
    int getRandom() {
        int x = rand()%v.size() ;
        return v[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

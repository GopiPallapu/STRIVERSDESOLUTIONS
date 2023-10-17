class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp ;
        for(auto str : magazine)
        {
            mp[str]++ ;
        }
        for(auto s : ransomNote)
        {
            if(mp.find(s) != mp.end()  && mp[s] > 0)
                mp[s]--;
            else
                return false;
        }
        return true ;
    }
};
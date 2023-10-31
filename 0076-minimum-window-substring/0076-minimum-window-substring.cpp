class Solution {
public:
    bool check(unordered_map<char,int> &map_s,unordered_map<char,int> &map_t){
        for(auto &itr: map_t){
            if(map_s[itr.first] < itr.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mapT , mapS ;
        for(auto itr : t)
        {
            mapT[itr]++ ;
        }
        int i =0, j =0 ,ansLen = INT_MAX , startIndex = 0;
        while(j < s.size())
        {
            mapS[s[j]]++ ;
            while(check(mapS , mapT))
            {
                if(ansLen >= j-i+1)
                {
                    ansLen = min(ansLen , j-i+1) ;
                    startIndex = i ;
                }
                mapS[s[i]]--;
                if(mapS[s[i]] == 0)
                    mapS.erase(s[i]) ;
                i++;
            }
            j++ ;
        }
        if(ansLen == INT_MAX)
            return "";
        else
            return s.substr(startIndex , ansLen);
    }
};
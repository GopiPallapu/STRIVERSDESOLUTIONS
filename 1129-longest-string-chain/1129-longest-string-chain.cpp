class Solution {
public:
    static bool cmp (string s1 , string s2)
    {
        return s1.size() < s2.size() ;
    } 
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , cmp) ;
        unordered_map<string , int> mp ;
        int answer  =0 ;

        for(string  word : words)
        {
            int length = 0; ;
            for(int i =0 ;i< word.size() ; i++)
            {
                string str = word ;
                str.erase(i , 1) ;
                length = max(length , mp[str]+1) ;
            }
            mp[word] = length ;
            answer = max(answer  ,length) ;
        }
        return answer ;
    }
};
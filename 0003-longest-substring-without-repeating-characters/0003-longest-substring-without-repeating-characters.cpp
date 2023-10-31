class Solution {
public:
    /*
        Input: s = "abcabcbb"
        Output: 3
    */
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st ;
        int n = s.size() ;
        int i=0,j =0 ;
        int maxLength =0 ;
        while( j < n)
        {
            if(st.count(s[j]) == 0)
            {
                st.insert(s[j]) ;
                maxLength = max(maxLength , j-i+1) ;
            }
            else
            {
                while(st.count(s[j]) > 0)
                {
                    st.erase(s[i]);
                    i++ ;
                }
                st.insert(s[j]) ;
            }
            j++ ;
        }
        return maxLength ;
    }
};
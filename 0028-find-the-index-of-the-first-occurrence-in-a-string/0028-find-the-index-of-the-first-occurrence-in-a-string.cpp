class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size() ;
        int index =-1 ;
        for(int i =0 ; i< n ; i++)
        {
            if(haystack[i] == needle[0])
            {
                if(haystack.substr(i , needle.size()) == needle)
                {
                    index = i ;
                    return index ;
                }
            }
        }
        return index ;
    }
};
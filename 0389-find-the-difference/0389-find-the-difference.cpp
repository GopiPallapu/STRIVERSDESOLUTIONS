class Solution {
public:
    char findTheDifference(string s, string t) {
        int c = 0;;
        for(auto cr : s)
        {
            c = c ^ cr ;
        }
        for(auto cr : t)
        {
            c = c ^ cr ;
        }
        return (char)c ;
    }
};
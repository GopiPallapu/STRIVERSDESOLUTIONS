class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end()) ;
        string answer = "" ;
        int n = strs.size() ;
        string st1 = strs[0], st2 = strs[n-1] ;
        for(int i =0 ; i < min(st1.size(), st2.size()); i++)
        {
            if(st1[i] != st2[i])
                return answer ;
            else
                answer += st1[i] ;
        }
        return answer ;
    }
};
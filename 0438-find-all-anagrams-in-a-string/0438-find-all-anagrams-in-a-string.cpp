class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 =s.size();
        int n2 = p.size() ;
        if(n2 > n1)return {} ;
        vector<int> freq (26,0);
        vector<int> window (26,0) ;
        for(int i =0 ;i< n2 ; i++)
        {
            freq[s[i]-'a']++;
            window[p[i]-'a']++;
        }
        vector<int> answer ;
        if(freq == window)
        {
            answer.push_back(0);
        }
        for(int i = n2 ; i< n1 ; i++)
        {
            freq[s[i-n2]-'a']--; // remove the index which is out of window range
            freq[s[i]-'a']++ ;
            if(window == freq)
            {
                answer.push_back(i-n2+1);
            }
        }
        return answer ;
        
    }
};
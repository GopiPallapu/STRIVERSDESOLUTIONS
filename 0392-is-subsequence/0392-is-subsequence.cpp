class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr1 =0 ; // pointer to iterate s 
        int ptr2 =0; // pointer to iterate t
        while(ptr1 < s.size() && ptr2 < t.size())
        {
            if(s[ptr1] == t[ptr2]) // if both mathces then increment both pointers  else inc only t pointer
            {
                ptr1 += 1 ;
            }
            ptr2 +=1 ;
        }
        return ptr1 == s.size(); // finallly check if s pointer reaches last means all chars are present in t
    }
};
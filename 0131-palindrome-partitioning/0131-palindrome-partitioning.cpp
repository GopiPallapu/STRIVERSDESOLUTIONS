class Solution {
public:
     bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
        if (s[start++] != s[end--])
            return false;
        }
        return true;
    }
    void help(int i , string &s ,vector<vector<string>> &ans , vector<string>&subset)
    {
        if(i == s.size())
        {
            ans.push_back(subset);
            return;
        }
        for(int index = i; index < s.size() ; index++)
        {
            if(isPalindrome(s,i , index))
            {
                subset.push_back(s.substr(i ,index-i+1));
                help(index+1 ,s,ans , subset);
                subset.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>> ans;
         vector<string> subset;
         help(0,s,ans,subset);
         return ans;
    }
};
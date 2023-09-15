class Solution {
public:
    bool helper(int index , string& s , unordered_set<string>& set , vector<int>& dp)
    {
        if(index == s.size())
        {
            return true;
        }
        if(dp[index] != -1)return dp[index];
        string temp = "";
        for(int i  =index ;i< s.size() ; i++)
        {
            temp +=s[i];
            if(set.find(temp) != set.end())
            {
                if(helper(i+1 , s, set,dp))
                {
                    return dp[index] = 1;
                }   
            }
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set ;
        vector<int> dp(301 , -1);
        for(auto str : wordDict )
        {
            set.insert(str);
        }
        return helper(0,s,set , dp);
    }
};
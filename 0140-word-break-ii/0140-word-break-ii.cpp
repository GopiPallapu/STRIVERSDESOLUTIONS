class Solution {
public:
    void helper(int index , string& s , string substr  ,vector<string>& answer, unordered_set<string>& words)
    {
        if(index == s.size())
        {
            substr.pop_back();
            answer.push_back(substr);
            return ;
        }
        string temp ="";
        for(int i = index ; i< s.size(); i++ )
        {
            temp +=s[i];
            if(words.find(temp) != words.end())
            {
                temp +=' ';
                helper(i+1 , s, substr+temp , answer , words);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> answer ;
        string substr = "";
        unordered_set<string> words ;
        for(auto str : wordDict)
        {
            words.insert(str);
        }
        helper(0,s,substr , answer, words);
        return answer;
    }
};
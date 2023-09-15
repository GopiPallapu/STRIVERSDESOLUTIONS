class Solution {
public:
    /*
        Approach:
        basic recurrsion and backtracking
        iterate throught string and find out word present in dict . if yes, add space  it 
        and add it substr and call recurrsion
        after that remove that space for other combination
        TC => O(n^2)
        SC => O(n)
    */
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
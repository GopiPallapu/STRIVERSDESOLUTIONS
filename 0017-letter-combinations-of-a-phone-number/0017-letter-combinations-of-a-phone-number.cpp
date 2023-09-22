class Solution {
public:
    void helper(int i , int n , string& temp ,vector<string>& answer , string& digits , unordered_map<char,string>& mp)
    {
        // base case
        if(i == n)
        {
            answer.push_back(temp);
            return ;
        }
        string str = mp[digits[i]];
        for(int k =0 ; k< str.size() ; k++)
        {
            temp.push_back(str[k]) ;
            helper(i+1 , n , temp ,answer , digits , mp);
            temp.pop_back() ;
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char ,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string> answer ;
        string temp ;
        int n = digits.size() ;
        if(digits == "")
            return {};
        helper(0 , n , temp , answer , digits , mp );
        return answer ;
    }
};
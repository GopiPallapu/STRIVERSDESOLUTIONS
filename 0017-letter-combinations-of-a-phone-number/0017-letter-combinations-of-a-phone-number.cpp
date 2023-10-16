class Solution {
public:
    void getTotalCombinations(int i , string& str , vector<string>& answer , map<char,string>& mp, string digits)
    {
        if( i == digits.size())
        {
            answer.push_back(str) ;
            return ;
        }
        
        string temp = mp[digits[i]] ;
        for(int j =0 ; j < temp.size() ; j++)
        {
            str.push_back(temp[j]);
            getTotalCombinations(i+1 , str , answer , mp , digits) ;
            str.pop_back() ;
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        map<char , string> mp ;
        mp['2'] = "abc" ;
        mp['3'] = "def" ;
        mp['4'] = "ghi" ;
        mp['5'] = "jkl" ;
        mp['6'] = "mno" ;
        mp['7'] = "pqrs" ;
        mp['8'] = "tuv" ;
        mp['9'] = "wxyz" ;
        
        string str ;
        vector<string> answer ;
        if(digits == "")
            return answer ;
        getTotalCombinations(0,str , answer , mp, digits);
        return answer ;
    }
};
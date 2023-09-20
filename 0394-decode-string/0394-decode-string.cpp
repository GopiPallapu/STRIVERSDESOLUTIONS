class Solution {
public:
    /*
        Approach :
        using recurrsion TC => O(n) SC => O(n)
        using stack , iteration method
    */
   
    string decodeString(string s) {
        int n = s.size() ;
        stack<int> stDigit ; // to store multiplier digits
        stack<string> stChars ; // to store substring to get multiplied
        int multiplier =0;
        string substring = "" ; // final answer string
        for(int i =0 ;i < n;i++)
        {
            if(isdigit(s[i]))
            {
                multiplier = multiplier * 10 + (s[i]- '0');
            }
            else if(s[i] == '[')
            {
                stDigit.push(multiplier) ; // push total digits till ' [ ' to stack and reset multiplier
                multiplier = 0;
                stChars.push(substring) ; // push current substring to stak and reset
                substring.clear();
            }
            else if( s[i] == ']')
            {
                int digit = stDigit.top() ; // get digit
                stDigit.pop() ;
                string str = stChars.top() ; //  get substring to get multiplied
                stChars.pop() ;
                while(digit -- )
                {
                    str +=substring ;
                }
                substring = str ; // add it to substring for any previous multiplications required 
            }
            else
            {
                substring +=s[i];
            }
        }
        return substring ;// final result
    }
};
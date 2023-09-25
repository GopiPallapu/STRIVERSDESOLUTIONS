class Solution {
public:
    int calculate(string s) {
        int n = s.size() ;
        int result =0;
        int sign =1;
        stack<int> st ;
        int num =0;
        for(int i =0;i< n ; i++)
        {
            if(isdigit(s[i]))
            {  
                while(i < n && isdigit(s[i]))
                {
                     num = num * 10 + (s[i]-'0');
                     i++;
                }
                i--;
                result += num * sign ;
                num =0;
                sign =1;
               
            }
            else if(s[i] =='-')
            {
                sign =-1;
            }
            else if(s[i] == '(')
            {
                st.push(result) ;
                st.push(sign) ;
                result =0;
                num =0;
                sign =1 ;
            }
            else if(s[i] ==')')
            {
                result  += num * sign; 
                num =0;
                sign = 1;
                int oldSign = st.top() ;
                st.pop() ;
                int oldResult = st.top() ;
                st.pop() ;
                result *= oldSign  ;
                result += oldResult ;
            }
        }
        result += (num*sign );
        return result;
    }
};
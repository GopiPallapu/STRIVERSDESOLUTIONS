class Solution {
public:
    bool isValid(string s) {
        int n = s.size() ;
        stack<int> st;
        for(int i =0 ;i < n ; i++)
        {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(! st.empty())
                {
                    char c = st.top();
                    if((s[i]==')' && c == '(') ||
                        (s[i]==']' && c == '[') ||
                        (s[i]=='}' && c == '{'))
                        st.pop();
                    else
                    return false;
                } 
                else return false;
                }
        }
        if(st.empty())return true;
        else return false;
    }
};
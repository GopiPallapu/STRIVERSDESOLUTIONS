class Solution {
public:
    /*
        Approach :
        using recurrsion TC => O(n) SC => O(n)
        using stack , iteration method
    */
   
    string decodeString(string s) {
        int n = s.size() ;
        stack<pair<int,string>> st ;// to store digit followed by string to diplay digit times
        string answer = "" ; // result string
        int i =0 ;
        while( i < n)
        {
            // case 1 - it is a digit
            if(s[i] - '0' >= 0 && s[i]-'0' <= 9)
            {
                int start = i ;
                while( (s[i] - '0' >= 0 && s[i]-'0' <= 9))
                {
                    i++;
                }
                int num = stoi(s.substr(start , i - start));
                st.push({num , ""});
                continue ;
            }
            // case 2 - it is a char take string attach it answer if stack empty 
            // else attach it to stack top string
            else if(s[i] - 'a' >= 0 && s[i]-'a' <= 26)
            {
                int start = i ;
                while( (s[i] - 'a' >= 0 && s[i]-'a' <= 26))
                {
                    i++;
                }
                string str = s.substr(start , i - start);
                if(!st.empty())
                {
                    st.top().second +=str ;
                }
                else
                {
                    answer += str ;
                }
                continue ;
            }
            // it is a closing bracket
            // take the top num - str , multiply the str num times and attach it to stack if not empty
            // if empty there is no digit in stack , attach it to answer
            else if(s[i] == ']')
            {
                    pair<int,string> p1 = st.top() ;
                    st.pop() ;
                    string nestr = "" ;
                    while(p1.first --)
                    {
                        nestr +=p1.second ;
                    }
                    if(!st.empty())
                    {
                        st.top().second += nestr ; // add it stack top
                    }
                    else
                        answer +=nestr ; // add it final answer
                    i++;
            }
            else
            {
                i++; // char is a opening bracker '['
            }
        }
        return answer ;
    }
};
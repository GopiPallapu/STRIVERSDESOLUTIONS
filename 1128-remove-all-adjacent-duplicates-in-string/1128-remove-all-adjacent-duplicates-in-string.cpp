class Solution {
public:
    string removeDuplicates(string s) {
       string answer ="";
       stack<int> st ;
       st.push(s[0]);
       for(int i =1 ;i < s.size() ; i++)
       {
           if(!st.empty() && st.top() == s[i])
           {
               st.pop() ;
           }
           else
                st.push(s[i]);
       }
       while(!st.empty())
       {
           answer += st.top() ;
           st.pop();
       }
       reverse(answer.begin() , answer.end());
       return answer ;
    }
};
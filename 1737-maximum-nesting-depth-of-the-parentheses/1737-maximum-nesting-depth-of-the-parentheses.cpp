class Solution {
public:
    int maxDepth(string s) {
        stack<int> st ;
        int n = s.size() ;
        int answer = 0 ;
        for(int i =0 ;i< n; i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if( !st.empty() && s[i] == ')')
            {
                st.pop() ;
            }
            int size = st.size() ;
            answer = max(answer,size);
        }
        return answer;
    }
};
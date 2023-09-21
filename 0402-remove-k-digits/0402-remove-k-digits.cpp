class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer = "" ;
        stack<char> st ;
        st.push(num[0]);
        for(int i =1 ;i < num.size() ; i++)
        {
            while(!st.empty() && st.top() > (num[i]) && k !=0) // stack - 1, 2, 1, 9
            {
                st.pop();
                k--;
            }
            st.push((num[i]));
            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
        while(k > 0 && !st.empty())
        {
            st.pop() ;
            k--;
        }
        while(!st.empty()) 
        {
            answer += st.top() ;
            st.pop() ;
        }
        reverse(answer.begin() , answer.end());
        if(answer.size() == 0)
            answer = "0";
        return answer ;
    }
};
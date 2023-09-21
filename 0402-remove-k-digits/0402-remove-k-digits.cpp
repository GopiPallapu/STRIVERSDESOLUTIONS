class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer = "" ;
        stack<char> st ;
        st.push(num[0]);
        for(int i =1 ;i < num.size() ; i++)
        {
            while(!st.empty() && st.top() > (num[i]) && k !=0) // stack - 0 , 
            {
                st.pop();
                k--;
            }
            st.push((num[i])); 
            // this will be used to remove any leading zeros before
            if(st.size() == 1 && num[i] == '0')
               st.pop();
        }
         // incase the stack is increasing order then no digit were popped till now . 
         // then we have to remove last k digits
         // eg : 14679 , then stack contains all digits .
        while(k > 0 && !st.empty())
        {
            st.pop() ;
            k--;
        }
        // push final stack nums to answer and reverse the string
        while(!st.empty()) 
        {
            answer += st.top() ;
            st.pop() ;
        }
        reverse(answer.begin() , answer.end());
        if(answer.size() == 0) // base case
            answer = "0";
        return answer ;
    }
};
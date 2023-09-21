class Solution {
public:
    string removeKdigits(string num, int k) {
		 // number of operation greater than length we return an empty string
        if(num.length() <= k)   
            return "0";
        string answer = "" ;
        stack<char> st ;
        //st.push(num[0]);
        for(int i =0 ;i < num.size() ; i++)
        {
            while(!st.empty() && st.top() > (num[i]) && k !=0) // stack - 1, 2, 1, 9
            {
                st.pop();
                k--;
            }
            if(num[i]  != '0') // ignore zeros
                    st.push((num[i]));
            else if(num[i] == '0' && !st.empty()) // add zeros if stack is not empty
                st.push(num[i]);
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
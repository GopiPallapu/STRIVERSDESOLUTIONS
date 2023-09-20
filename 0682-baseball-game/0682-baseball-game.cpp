class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st ;
        int n = operations.size();
        int answer =0;
        for(int i =0 ;i< n; i++)
        {
            if(operations[i] == "+")
            {
                int a = st.top() ;
                st.pop() ;
                int b = st.top() ;
                st.push(a) ;
                st.push(a+b);
                answer +=st.top();
            }
            else if(operations[i] == "D")
            {
                st.push(st.top() * 2);
                 answer +=st.top();
            }
            else if(operations[i] == "C")
            {
                 answer -=st.top();
                st.pop() ;
                
            }
            else
            {
                string s = operations[i];
                int x = 0;
                int neg = 0;
                for(auto c : s)
                {
                    if(c >= '0' && c<= '9')
                        x = x * 10 + (c-'0'); 
                    else
                        neg = 1;
                }
                if(neg == 1)
                    x = -x ;
                st.push(x);
                cout<< x << endl;;
                 answer +=st.top();
            }
        }
        return answer;
    }
};
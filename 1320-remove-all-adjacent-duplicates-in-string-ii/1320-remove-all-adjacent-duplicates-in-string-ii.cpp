class Solution {
public:
    // using stack or vector array we can solve this
    // TC => O(n)
    // SC => O(n)
    string removeDuplicates(string s, int k) {
        int n = s.size() ;
        if(k > n) return s ;
        stack<pair<char , int>> st ;
        string answer = "";
        
        for(int i =0 ;i < n ; i++)
        {
            if(st.empty() || st.top().first != s[i])
            {
                st.push({s[i]  , 1});
            }
            else
            {
                pair < char , int> p1  =st.top() ;
                st.pop() ;
                p1.second +=1;
                st.push(p1);
            }

            // check for k duplicates
            if(st.top().second == k)
                st.pop() ;
        }

        // take the result into answer string
        while(!st.empty())
        {
            pair<char,int> p1 = st.top() ;
            while(p1.second -- )
            {
                answer +=p1.first ;
            }
            st.pop();
        }
        reverse(answer.begin() , answer.end());
        return answer;
    }
};
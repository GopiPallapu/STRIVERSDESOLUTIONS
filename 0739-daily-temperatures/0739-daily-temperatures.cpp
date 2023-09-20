class Solution {
public:
    /*
        Approach :
        using monotonic increasing stack we can push temparatures with index from right to left
        TC => O(n)
        SC => O(n)
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size() ;
        vector<int> answer (n , 0) ;
        stack<pair<int,int>> st ;
        for(int i = n-1 ; i >= 0;i--)
        {
            int val = 1;
            while(!st.empty() && st.top().first <= temperatures[i])
            {
                val +=st.top().second ;
                st.pop() ;
            }
            if(!st.empty())
                answer[i] = val ;
            st.push({temperatures[i] , val}) ;
        }
        return answer ;
    }
};
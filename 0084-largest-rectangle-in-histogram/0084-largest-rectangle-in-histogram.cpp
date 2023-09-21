class Solution {
public:
    // right vector
    // 1, 6, 4, 4, 6, 6
    // -1,-1,1,2,1,4
    //  2 , 6, 10, 6, 8 , 3
    // 2,2
    // -1,0
    // 4,4
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st ;
        int n = heights.size() ;
        vector<int> right(n, n);
        for(int i = n-1 ;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        // right - 1,-1,2,2,-1,-1
        vector<int> left(n,-1);
        for(int i = 0 ;i < n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }
        // left - -1,-1,1,5,1,2
        int answer  =INT_MIN ;
        for(int i =0 ; i < n; i++)
        {
            int area = (right[i] - left[i] - 1) * heights[i];
            answer = max(answer  , area);
        }
        return answer;
    }
};
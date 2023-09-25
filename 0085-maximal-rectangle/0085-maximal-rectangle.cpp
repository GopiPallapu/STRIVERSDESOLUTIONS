class Solution {
public:
    //Input: heights = [2,1,5,6,2,3]
    //Output: 10
   void leftSmallerElement(vector<int>& nums , vector<int>& answer) {
		int n = nums.size() ;
        stack<int> st ;
        for(int  i = 0 ; i < n; i++)
        {
            while(!st.empty() && nums[i] <= nums[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                answer[i] = (st.top())+1;
            }
            st.push(i);
        }
	}
	void rightSmallerElement(vector<int>& nums , vector<int>& answer) {
		int n = nums.size() ;
        stack<int> st ;
        for(int  i = n - 1 ; i>= 0; i--)
        {
            while(!st.empty() && nums[i] <= nums[st.top()])
            {
                st.pop();
            }
            if(!st.empty() )
            {
                answer[i] = (st.top())-1;
            }
            st.push(i);
        }
	}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector<int> lse (n , 0) ;
        leftSmallerElement(heights , lse);
        vector<int> nse (n , n-1) ;
        rightSmallerElement(heights ,nse) ;
        
        int answer =0;
        for(int i =0 ; i < n ; i++)
        {
            int x = (nse[i]-lse[i]+ 1 ) * heights[i];
            answer =  max(answer , x) ;
        }
        return answer ;
    }
	int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<int> heights(m ,0);
        int answer =0;
        for(int i =0 ;i< n ;i++)
        {
            for(int j =0 ;j< m ; j++)
            {
                if(matrix[i][j]-'0' == 1)
                {
                    heights[j] ++;
                }
                else
                {
                    heights[j] = 0;
                }
            }
            answer = max(answer , largestRectangleArea(heights));
        }
        return answer ;
    }
    
};
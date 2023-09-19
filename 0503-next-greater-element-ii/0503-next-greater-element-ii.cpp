class Solution {
public:
    // 1,2,1,1,2,1
    // because of this circular array , we have to traverse double the size;
    //  using stack we can store max element
    // TC => O(n) SC => O(n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> temp  = nums ;
        vector<int> answer(n , -1) ;
        /*for(int i =0 ;i< n ; i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i = 0 ; i< n;i++)
        {
            int x  = nums[i];
            int j = i+1;
            while(j < temp.size())
            {
                if(temp[j] > x)
                {
                    x = temp[j];
                    break;
                }
                j++;
            }
            if(x != nums[i])
                answer.push_back(x);
            else
                answer.push_back(-1);
        }*/
        stack<int> st ;
        for(int  i = 2*n - 1 ; i>= 0; i--)
        {
            while(!st.empty() && nums[i%n] >= st.top())
            {
                st.pop();
            }
            if(!st.empty() && (i < n))
            {
                answer[i] = (st.top());
            }
            st.push(nums[i%n]);
        }
        return answer;
    }
};
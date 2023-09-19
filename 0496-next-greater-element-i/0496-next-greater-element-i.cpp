class Solution {
public:
    int getNextElement(int x , vector<int>& nums )
    {
        int res  = -1;
        for(int i = 0; i < nums.size() ; i++)
        {
            if(nums[i] == x)
            {
                for(int j = i+1 ; j< nums.size() ; j++)
                {
                    if(nums[j] > nums[i])
                    {
                        res = nums[j];
                        break;
                    }
                }
                if(res != -1)
                    break;
            }
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer ;
        int n1 = nums1.size();
        int n2 = nums2.size() ;

        // iterate through first array

        unordered_map<int,int> mp;
        stack<int> st;

        /*for(int i =0 ;i< n1 ; i++ )
        {
            answer.push_back(getNextElement(nums1[i] , nums2));
        }*/
        for(int i = n2 - 1 ; i>= 0 ;i--)
        {
            while(!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i =0 ;i< n1 ; i++)
        {
            answer.push_back(mp[nums1[i]]);
        }
        return answer;
    }
};
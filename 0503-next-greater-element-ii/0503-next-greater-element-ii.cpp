class Solution {
public:
    // 1,2,1,1,2,1
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> temp  = nums ;
        vector<int> answer ;
        for(int i =0 ;i< n ; i++)
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
        }
        return answer;
    }
};
class Solution {
public:
    // 324
    // 3,2,4
    int nextGreaterElement(int x) {
        vector<int>nums;
        while(x>0)
        {
            nums.push_back(x%10);
            x/=10;
        } 
        int i;
        int n = nums.size();
        reverse(nums.begin() , nums.end());
        for(i = n-1 ; i > 0 ;i--)
        {
            if(nums[i -1] < nums[i])
            {
                break;
            }
        }
        if(i == 0)
            return -1;
        int element = nums[i-1];
        int smallest =i;
        for(int j = i+1 ; j< n;j++)
        {
            if(nums[j] > element && nums[j]<= nums[smallest] )
            {
                smallest = j;
            }
        }
        swap(nums[i-1], nums[smallest]);
        sort(nums.begin()+i,nums.end());
        
        long long int answer = 0;
        for(int i =0; i<n ; i++)
        {
            answer = answer * 10 ;
            answer +=nums[i];
        }
        return (answer > INT_MAX) ? -1 : (int)answer;
    }
};
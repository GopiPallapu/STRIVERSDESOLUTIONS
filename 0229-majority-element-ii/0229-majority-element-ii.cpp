class Solution {
public:
    // using moore voting algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int element1  =0 ;
        int element2  =0 ;
        int count1 =0;
        int count2 = 0;
        int n = nums.size();
        for(int i =0 ;i< n ; i++)
        {
            if(count1 == 0 && element2 != nums[i])
            {
                element1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && element1 != nums[i])
            {
                element2 = nums[i];
                count2 = 1;
            }
            else if(element1 == nums[i])
                count1 +=1;
            else if(element2 == nums[i])
                count2 +=1;
            else
            {
                count1 --;
                count2 --;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
          if(element1 == nums[i])count1++;
          if(element2 == nums[i])count2++;
        }
        vector<int> ans;
        if(count1 > n/3 )
          ans.push_back(element1);
        if(count2 > n/3 && element1 != element2)
          ans.push_back(element2);
        return ans;

    }
};
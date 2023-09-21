class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq(k ,0) ;
        vector<int> answer ;
        // push first k elements to dq and compare elements which is max and remove small elements
        for(int i =0 ;i < k; i++)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // after first k elemets insertion queue contains max element index at front
        // add that element to answer
        answer.push_back(nums[dq.front()]);
        // iterate through next n-k elements and find the max in each window
        for(int i = k ; i < n ; i++)
        {
            // remove indexs which are out of window range
            while(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }
            // removes indexs whose val is smaller than current nums[i]
            while(!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            // for this window the max element index is at front
            answer.push_back(nums[dq.front()]);
        }
        return answer;
    }
};
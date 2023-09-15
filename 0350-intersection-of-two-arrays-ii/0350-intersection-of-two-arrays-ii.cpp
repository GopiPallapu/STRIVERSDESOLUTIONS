class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2)return intersect(nums2 ,nums1);

        unordered_map<int,int> mp;
        for(int i =0 ;i < n1 ; i++)
        {
            mp[nums1[i]]++;
        }
        //
         vector<int> answer ;
        for(int i =0 ;i< n2 ; i++)
        {
            if(mp[nums2[i]] > 0)
            {
                answer.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return answer;
    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         map<int,int>subElements;
        subElements.insert({0,1});
        int ans=0;
        int sum=0;
        for(int x:nums){
            sum+=x;
            int rem = sum%k;
            if(rem <0)rem+=k;
            auto it = subElements.find(rem);
            if(it!=subElements.end()){
                ans+=it->second;
            }
           subElements[rem]++;

        }
        return ans;
    }
};
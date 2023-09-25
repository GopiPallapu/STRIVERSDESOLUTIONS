class Solution {
public:
    // using binary search will found the median os the two sorted lists
    // TC -> O(log(min(n1,n2)))
    // SC -> O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size() ;
       int n2 = nums2.size() ;
       if(n1 > n2)
            return findMedianSortedArrays(nums2 , nums1) ;
        int n = (n1+n2) ;
        
        int partiton = (n+1)/2 ;
        
        int cut1 =0;
        int cut2 =0;
        int left =0;
        int right = n1 ;
        while(left <= right)
        {
            int mid = (left+right)/2 ;
            cut1 = mid ;
            cut2 = partiton - cut1 ;
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1] ;
            int r1 = cut1 >= n1 ? INT_MAX : nums1[cut1] ;
            
            int l2 = cut2 ==0 ? INT_MIN : nums2[cut2-1] ;
            int r2 = cut2 >= n2 ? INT_MAX : nums2[cut2] ;
            
            // correct partition
            if(l1 <= r2 && l2 <= r1)
            {
                if( n%2 == 1)
                {
                    return max(l1 , l2);
                }
                else
                {
                    return (max(l1 ,l2)+ min(r1,r2))/2.0 ;
                }
            }
            else if( l1 > r2)
            {
                right = cut1-1 ;
            }
            else
            {
                left = cut1+1 ;
            }
        }
        return 0.0 ;
    }
};
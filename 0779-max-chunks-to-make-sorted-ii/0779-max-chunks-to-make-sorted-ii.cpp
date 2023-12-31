class Solution {
public:
    // using prefix and suffix array
    // TC => O(n)
    // SC => O(n)
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> prefixMax (n , 0);
        prefixMax[0] = arr[0];

        for(int i = 1 ; i< n ;i++)
        {
            prefixMax[i] = max(prefixMax[i-1] , arr[i]);
        }
        vector<int>suffixMin (n , 0);
        suffixMin[n-1] = arr[n-1];

        for(int i = n-2 ; i>= 0;i--)
        {
            suffixMin[i] = min(suffixMin[i+1] , arr[i]);
        }
        
        int answer = 1 ;
        for(int i =0; i<n-1 ; i++)
        {
            if(prefixMax[i] <= suffixMin[i+1])
            {
                answer +=1;
            }
        }
        return answer;
    }
};

// prefixMax 
// [1,1,2,3,4]
// [0,0,2,3,4]


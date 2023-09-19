class Solution {
public:
    // 324
    // 3,2,4
    int nextGreaterElement(int x) {
       string str = to_string(x);
       int i;
       int n = str.size();
       for( i = n-1 ;i>0 ;i--)
       {
           if(str[i-1] < str[i])
           {
               break;
           }
       }
       if(i == 0)
       {
           return -1;
       }
       int element = str[i-1];
       int smallest = i ;
       for(int j = i+1 ; j< n;j++)
       {
           if(str[j] > element && str[j] <= str[smallest])
           {
               smallest = j;
           }
       }
       swap(str[i-1] , str[smallest]);
       sort(str.begin()+i , str.end());
       long  ans = stol(str);
      if(ans > INT_MAX)return -1;
      else
        return (int)ans;
    }
};
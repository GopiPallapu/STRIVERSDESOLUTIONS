class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = (long long ) dividend ;
        long long b = (long long ) divisor  ;
        
        if(a == INT_MIN && b == -1) return INT_MAX ;
        if(a == INT_MIN && b == 1) return INT_MIN ;
        
        bool sign = (a> 0) == (b > 0) ? true : false ;
        
        a = abs(a) ;
        b = abs(b) ;
        
        long long answer =0 , temp =0;
        for(int i = 31 ; i>=0 ;i--)
        {
            if(temp + (b << i) <= a)
            {
                temp += (b << i) ;
                answer += (1 << i);
            }
        }
        if(sign  == false)
            answer = answer * -1;
        return (int)answer ;
    }
};
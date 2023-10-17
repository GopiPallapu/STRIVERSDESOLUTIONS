class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        
        int carry = 0;
        string answer ="";
        while( i >= 0 || j >=0 || carry == 1)
        {
            if(i >= 0)
            {
                carry +=a[i--]-'0'; 
            }
            if(j >= 0)
            {
                carry += b[j--]-'0';
            }
            answer += carry%2 + '0';
            carry  = carry/2 ;
        }
        reverse(answer.begin(),answer.end()) ;
        return answer ;
    }
};
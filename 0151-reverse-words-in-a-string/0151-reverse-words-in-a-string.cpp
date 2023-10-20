class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() ;
        int i =0 , j = n-1 ;
        while(j >= 0 && s[j] == ' ')
            j--;
        while(i < n && s[i] == ' ')
            i++ ;
        string answer = "" , temp = "";
        while( j >= i)
        {
            if(s[j] == ' ')
            {
                if(temp != "")
                {
                    reverse(temp.begin(), temp.end()) ;
                    answer += temp +" ";
                }
                temp ="";
            }
            else
                temp +=s[j];
            j-- ;
        }
        if(temp != "")
        {
            reverse(temp.begin(), temp.end()) ;
             answer += temp ;
        }
        return answer ;
    }
};
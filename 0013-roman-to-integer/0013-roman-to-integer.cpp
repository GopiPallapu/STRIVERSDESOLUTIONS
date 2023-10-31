class Solution {
public:
    int romanToInt(string s) {
        map<char,int > mRoman;
        mRoman['I']=1;
        mRoman['V']=5;
        mRoman['X']=10;
        mRoman['L']=50;
        mRoman['C']=100;
        mRoman['D']=500;
        mRoman['M']=1000;
        
        int answer =0;
        for(int i = s.size()-1 ; i>= 0 ; i--)
        {
            if(i < s.size()-1 && mRoman[s[i]] < mRoman[s[i+1]])
            {
                answer -= mRoman[s[i]] ;
            }
            else
                answer += mRoman[s[i]] ;
        }
        return answer ;
    }
};
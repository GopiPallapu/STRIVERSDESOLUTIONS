class Solution {
public:
    void helper(int index , int n , string& s  ,vector<string>& answer)
    {
        if(index == n)
        {
            answer.push_back(s);
            return;
        }
        for(int i = index ; i < n ; i++)
        {
            swap(s[i],s[index]);
            helper(index+1 , n , s , answer);
            swap(s[i] , s[index]);
        }
        return ;
    }
    string getPermutation(int n, int k) {
       /* string input ;
        for(int i =1 ;i<= n;i++)
        {
            input.push_back(i+'0');
        }
        vector<string> answer;
        helper(0,n,input,answer);
        sort(answer.begin() , answer.end());
        return answer[k-1];*/

        // mathematicsl approach
        vector<int> numbers ;
        int fact =1;
        // calculate n-1 th factorial 
        for(int i = 1 ;i< n ; i++ )
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n) ; // store numbers from 1 to n
        k = k-1 ; // o based indexing  -- k th sequence means k-1 th one
        
        string answer = "";  // result

        while(true)
        {
            answer =  answer + to_string(numbers[k / fact]); // get first index in the result
            numbers.erase(numbers.begin()+( k / fact )); //  remove that index from input

            if(numbers.size() == 0)
            {
                break;
            }

            k = k % fact; // get next index 
            fact = fact / numbers.size(); // decrement fact to size() -1
        }

        return answer;


    }
};
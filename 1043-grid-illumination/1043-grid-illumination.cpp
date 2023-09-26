
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> answer ; // to store the answer
        unordered_map<int,int> row , col , antiD , mainD ; // row  , col , main Diagonal , AntiDiagonal
        set<pair<int,int>> lm ; // trun on lamps
        for(auto var : lamps)
        {
            int x = var[0] ;
            int y = var[1] ;
            if(lm.find({x,y}) == lm.end()) // {0,0} {4,4}
            {
                lm.insert({x,y}) ;
                row[x]++ ;
                col[y]++ ;
                antiD[x+y]++ ;
                mainD[x-y]++ ;
            }
        }
        // row - 0-1,4-1 , col- 0-1 ,4-1 , antiD - 0 -1,8-1 , mainD- 0 - 2
        for(auto var : queries)
        {
            int x = var[0] ; // 1
            int y = var[1] ; // 0
            if(row[x] > 0 || col[y] > 0 || antiD[x+y] > 0 || mainD[x-y] > 0)
            {
                answer.push_back(1);
                for(int i  =-1 ; i<=1 ; i++)
                {
                    for(int j = -1 ; j<= 1 ; j++)
                    {
                        int nx = x+i ; // 0
                        int ny = y+j ; // 
                        if(nx >= 0 && nx < n && ny >= 0 && nx < n && lm.find({nx,ny}) != lm.end() )
                        {
                            lm.erase({nx,ny}) ; // 4,4
                            row[nx] --; // 0-0 , 4-1
                            col[ny] --; // 0-0 , 4-1
                            antiD[nx+ny] --; // 0-0 , 8-1
                            mainD[nx-ny] --; // 0-1
                        }
                    }
                }
                
            }
            else
            {
                answer.push_back(0);
            }
            
        }
        return answer ;
    }
};

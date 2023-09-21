class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        // create a queue of pair to store indexs of rotten oranges
        queue<pair<int,int>> dq ;
        int total = 0; // total count of oranges (rotten + fresh)
        for(int i =0 ;i< m ; i++)
        {
            for(int j =0 ; j< n ; j++)
            {
                if(grid[i][j] != 0) total +=1;
                if(grid[i][j] == 2)
                {
                    dq.push({i ,j});
                }
            }
        }
        int count  =0 ; // total count of oranges (rotten + fresh)
        int answer  =0;
        int dx[4] = {0, 0, 1, -1}; // x - coordinates
        int dy[4] = {1, -1, 0, 0}; // y - coordinates
        while(!dq.empty())
        {
            int k = dq.size();
            count += k;
            while(k--)
            {
                int x = dq.front().first ;
                int y = dq.front().second ;
                dq.pop() ;
                for(int i =0 ;i < 4 ; i++)
                {
                    int x1 = x + dx[i] ;
                    int y1 = y + dy[i] ;

                    if(x1 < 0 || y1 < 0 || x1 >= m || y1 >= n || grid[x1][y1] != 1)
                    {
                        continue; // already rotten skip it
                    }
                    grid[x1][y1] = 2; // make it rotten and add it queue
                    dq.push({x1 , y1});
                }
            }
            if(!dq.empty()) // still some orange are available for rotten 
            {
                answer +=1 ;// increasing the no of days required
            }
        }
        if(total == count) //total count of oranges (rotten + fresh) equals count
            return answer ; // all oranges are rotten
        else
            return -1; // some of the oranges are not rotten and not possible
    }
};
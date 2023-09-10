class Solution {
public:
    vector<vector<int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}};
    int res= 1e9;
    void dfs(vector<vector<int>>& grid, int moves)
    {
        int count1=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j]==1)
                    count1++;
            }
        }
        
        if(count1==9)
        {
            res= min(res,moves);
            return;
        }
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    for(int l=0; l<3; l++)
                    {
                        if(grid[i][j]==0 && grid[k][l]>1)
                        {
                            int dist= abs(k-i)+ abs(l-j);
                            grid[i][j]++;
                            grid[k][l]--;
                            dfs(grid, moves+ dist);
                            grid[i][j]--;
                            grid[k][l]++;
                        }
                    }
                }
                
            }
        }
        
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        
        dfs(grid,0);
        return res;
        
    }
};
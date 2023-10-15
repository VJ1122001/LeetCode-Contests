class Solution {
public:
    int mod= 12345;
    
    void printV(vector<vector<int>>& grid)
    {
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<long long>> tLbR(n, vector<long long>(m));
        vector<vector<long long>> bRtL(n, vector<long long>(m));
        vector<vector<long long>> tRbL(n, vector<long long>(m));
        vector<vector<long long>> bLtR(n, vector<long long>(m));
        vector<vector<long long>> rowPrefix(n, vector<long long>(m));
        vector<vector<long long>> rowSuffix(n, vector<long long>(m));
        vector<vector<long long>> colPrefix(m, vector<long long>(n));
        vector<vector<long long>> colSuffix(m, vector<long long>(n));
        
        
        // TopLeft to BottomRight
        for(int i=0; i<n;i++)
        {
            long long rowProd=1;
            for(int j=0; j<m; j++)
            {
                rowProd *= grid[i][j];
                
                if(i>0)
                    tLbR[i][j]= (tLbR[i-1][j]* rowProd)% mod;
                else
                    tLbR[i][j]= (rowProd)% mod;
                
                rowProd %= mod;
                rowPrefix[i][j]= rowProd;
            }
        }
        
        //TopRight to BottomLeft
        for(int i=0; i<n; i++)
        {
            long long rowProd=1;
            for(int j=m-1; j>=0; j--)
            {
                rowProd *= grid[i][j];
                
                if(i>0)
                    tRbL[i][j]= (tRbL[i-1][j]* rowProd)% mod;
                else
                    tRbL[i][j]= (rowProd)% mod;
             
                rowProd %= mod;
                rowSuffix[i][j]= rowProd;
            }
        }
        
        //BottomRight to TopLeft
        for(int i=n-1; i>=0 ;i--)
        {
            long long rowProd=1;
            for(int j=m-1; j>=0; j--)
            {
                rowProd *= grid[i][j];
                
                if(i<n-1)
                    bRtL[i][j]= (bRtL[i+1][j]* rowProd)% mod;
                else
                    bRtL[i][j]= rowProd% mod;
                
                rowProd %= mod;
            }
        }
        
        //BottomLeft to TopRight
        for(int i=n-1; i>=0 ;i--)
        {
            long long rowProd=1;
            for(int j=0; j<m; j++)
            {
                rowProd *= grid[i][j];
                if(i<n-1)
                    bLtR[i][j]= (bLtR[i+1][j]* rowProd)% mod;
                else
                    bLtR[i][j]= rowProd% mod;
                
                rowProd %= mod;
            }
        }
        
        for(int j=0; j<m; j++)
        {
            long long colProd=1;
            for(int i=0; i<n;i++)
            {
                colProd*= grid[i][j];
                
                colProd%= mod;
                
                colPrefix[j][i]= colProd;
            }
        }
        
        for(int j=0; j<m; j++)
        {
            long long colProd=1;
            for(int i=n-1; i>=0 ;i--)
            {
                colProd*= grid[i][j];
                
                colProd%= mod;
                
                colSuffix[j][i]= colProd;
            }
        }
        
        // printV(tLbR);
        // printV(bRtL);
        // printV(tRbL);
        // printV(bLtR);
        // printV(rowPrefix);
        // printV(rowSuffix);
        // printV(colPrefix);
        // printV(colSuffix);
        
        vector<vector<int>> ans(n, vector<int>(m,0));
        
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                long long prod=1;
                
                if(i-1 >= 0 && j-1 >= 0)  
                {
                    prod*= tLbR[i-1][j-1];
                    prod%= mod;
                }
                
                if(i-1 >= 0 && j+1 < m) 
                {
                    prod*= tRbL[i-1][j+1];
                    prod%= mod;
                }
                
                if(i+1 < n && j-1 >= 0) 
                {
                    prod*= bLtR[i+1][j-1];
                    prod%= mod;
                }
                
                if(i+1 < n && j+1 < m) 
                {
                    prod*= bRtL[i+1][j+1];
                    prod%= mod;
                }
                
                if(j-1 >= 0) 
                {
                    prod*= rowPrefix[i][j-1];
                    prod%= mod;
                }
                
                if(j+1 < m) 
                {
                    prod*= rowSuffix[i][j+1];
                    prod%= mod;
                }
                
                if(i-1 >=0) 
                {
                    prod*= colPrefix[j][i-1];
                    prod%= mod;
                }
                
                if(i+1 < n) 
                {
                    prod*= colSuffix[j][i+1];
                    prod%= mod;
                }
                
                ans[i][j]= prod% mod;
            }
        }
        
        return ans;
        // return {{}};
        
    }
};
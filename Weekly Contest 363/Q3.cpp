class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        long long result=0;
        
        for(auto m: composition)
        {
            long long l= 0;
            long long h= 1e10;
            long long ans= 0;
            
            while(l<=h)
            {
                long long mid= (l+h)/2;
                long long temp=0;
                
                for(int j=0;j<n;j++)
                {
                    long long reqd= m[j]* mid;
                    
                    if(stock[j] >= reqd)
                        continue;
                    else
                    {
                        reqd-= stock[j];
                        temp+= reqd* cost[j];
                    }
                }
                
                
                if(temp <= budget)
                {
                    ans= max(ans, mid);
                    l= mid+1;
                }
                else
                    h= mid-1;
            }  
            
            result= max(result,ans);
        }
        
        return result;
        
    }
};
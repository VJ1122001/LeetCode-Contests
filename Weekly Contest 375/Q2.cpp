class Solution {
public:
    
    long long modExp(long long a, long long b, long long m)
    {
        long long res=1;
        
        while(b > 0)
        {
            if(b%2)
            {
                res*= (a % m);
                b--;
            }
            else
            {
                a= ((a*a)% m);
                b/=2;
            }
        }
        
        return res % m;
    }
    
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        
        int n= variables.size();
        
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            vector<int> v= variables[i];
            int a= v[0];
            int b= v[1];
            int c= v[2];
            int m= v[3];
            
            long long fm= modExp(a,b, 10);
            long long sm= modExp(fm,c, m);
            
            // cout<<sm<<endl;
            
            if(sm == target)
                ans.push_back(i);
        }
        
        return ans;
    }
};
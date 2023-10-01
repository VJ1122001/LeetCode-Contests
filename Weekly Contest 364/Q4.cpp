class DSU {
public:
    
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,1);
        size.resize(n,1);
        
        for(int i=0;i<n;i++)
            parent[i]= i;
    }
    
    int find(int x)
    {
        if(x== parent[x])
            return x;
        return find(parent[x]);
    }
    
    void Union(int x, int y)
    {
        int px= find(x);
        int py= find(y);
        
        if(px!= py)
        {
            if(rank[px] > rank[py])
            {
                parent[py]= px;
                size[px]+= size[py];
                size[py]=0;
            }
            else if(rank[py] > rank[px])
            {
                parent[px]= py;
                size[py]+= size[px];
                size[px]=0;
            }
            else
            {
                rank[px]++;
                parent[py]= px;
                size[px]+= size[py];
                size[py]=0;
            }
        }
    }
    
};

vector<bool> isPrime;
class Solution {
public:
    void buildSieve()
    {
        if(isPrime.empty())
        {
            isPrime.resize(100001, true);
            isPrime[0]= isPrime[1]= false;
            
            for(long long i=2; i<100002 ; i++)
            {
                if(isPrime[i])
                {
                    for(long long j= i*i; j<100002; j+=i)
                    {
                        isPrime[j]= false;
                    }
                }
            }
        }
    }
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        
        DSU dsu(n+1);
        buildSieve();
        vector<vector<int>> graph(n+1);
        
        for(auto edge: edges)
        {
            int u= edge[0]; int v= edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            
            if(isPrime[u] || isPrime[v])
                continue;
            
            dsu.Union(u,v);
        }
        
        
        long long result=0;
        
        for(int i=1; i<=n; i++)
        {
            if(isPrime[i])
            {
                long long ans=0;
                long long sum=1;
                for(auto x: graph[i])
                {
                    if(!isPrime[x])
                    {
                        sum+= dsu.size[dsu.find(x)];
                    }
                }
                
                // cout<<i<<" "<<sum<<endl;
                
                for(auto x: graph[i])
                {
                    if(!isPrime[x])
                    {
                        // cout<<dsu.size[dsu.find(x)]<<endl;
                        sum-= dsu.size[dsu.find(x)];
                        ans+= dsu.size[dsu.find(x)]* sum;
                    }
                }
                
                result+= ans;
            }
        }
        
        return result;
    }
};
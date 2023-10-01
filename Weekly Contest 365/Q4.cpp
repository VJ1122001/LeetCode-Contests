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

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        //For all the nodes in the cycle the answer would be all the nodes in the cycle
        //For all the other nodes the answer would be the distance from the entry point of the cycle + the cyclc nodes
        
        int n= edges.size();
        DSU dsu(n); 
        vector<bool> isCycle(n, true);
        vector<int> indegree(n,0);
        
        vector<vector<int>> graph(n);
        
        for(int i=0;i<n;i++)
        {
            int u= i;
            int v= edges[i];
            
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> tq;
        
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                tq.push(i);
        
        while(!tq.empty())
        {
            auto x= tq.front();
            tq.pop();
            isCycle[x]= false;
            
            for(auto y: graph[x])
            {
                indegree[y]--;
                if(indegree[y]==0)
                    tq.push(y);
            }
        }
        
        for(int i=0 ;i<n;i++)
        {
            int u= i;
            int v= edges[i];
            
            if(isCycle[u] && isCycle[v])
                dsu.Union(u,v);
        }
        
        
        vector<int> whichCycle(n,-1);
        vector<int> ans(n,0);
        queue<int> q;
        for(int i=0; i<n; i++) 
        {
            if(isCycle[i]) 
            {
                q.push(i);
                ans[i]= dsu.size[dsu.find(i)];
                whichCycle[i]= dsu.find(i);
            }
        }
        
        // for(int i=0; i<n; i++)
        //     cout<<isCycle[i]<<" ";
        // cout<<endl;
        
        
        vector<vector<int>> revGraph(n);
        
        for(int i=0;i<n;i++)
        {
            int v= i;
            int u= edges[i];
            
            revGraph[u].push_back(v);
        }
        
        int level=1;
        while(!q.empty())
        {
            int sz= q.size();
            
            for(int i=0;i<sz;i++)
            {
                auto cur= q.front();
                q.pop();
                
                for(auto nbr: revGraph[cur])
                {
                    if(!isCycle[nbr])
                    {
                        q.push(nbr);
                        ans[nbr]= dsu.size[whichCycle[cur]]+ level;
                        isCycle[nbr]= isCycle[cur];
                        whichCycle[nbr]= whichCycle[cur];
                    }
                }
            }
            
            level++;
        }
        
        return ans;
        
    }
};
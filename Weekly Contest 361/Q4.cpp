class Solution {
public:
    const int LOG= 14;
    vector<vector<int>> tree;
    vector<vector<int>> par;
    vector<int> level;
    
    void liftNode(int& node1, int& node2)
    {
        if(level[node1]== level[node2])
            return;
        
        int l1= level[node1];
        int l2= level[node2];
        if(l1> l2)
        {
            swap(node1, node2);
            swap(l1,l2);
        }
        
        // cout<<l1<<" "<<l2<<" "<<node1<<" "<<node2<<endl;
        
        int diff= l2-l1;
        for(int i=0;i<LOG;i++)
        {
            if((1<<i)& diff)
            {
                node2= par[i][node2];
                // cout<<node2<<endl;
            }
        }   
    }
    
    int LCA(int node1, int node2)
    {   
        liftNode(node1,node2);
        if(node1== node2) return node1;

        // cout<<node1<<" "<<node2<<endl;
        
        if(par[0][node1]== par[0][node2])
            return par[0][node1];
        
        int i=1;
        while(par[i][node1]!= par[i][node2])
        {
            // cout<<i<<endl;
            i++;
        }
        
        // cout<<i<<" "<<node1<<" "<<node2<<endl;
        
        return LCA(par[i-1][node1],par[i-1][node2]);
    }
    
    vector<vector<int>> rootToNode;
    void dfs(vector<vector<pair<int,int>>>& graph, int src, int parent)
    { 
        // cout<<par<<" "<<src<<endl;
        for(auto x: graph[src])
        {
            if(x.first!= parent)
            {  
                tree[src].push_back(x.first);
                par[0][x.first]= src;
                level[x.first]= level[src]+1;
                rootToNode[x.first]= rootToNode[src];
                rootToNode[x.first][x.second]++;
                dfs(graph, x.first, src);
            }
        }
    }
    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        rootToNode.resize(n, vector<int>(27,0));
        tree.resize(n);
        
        par.resize(LOG, vector<int>(n,-1));
        level.resize(n);
        
        vector<vector<pair<int,int>>> graph(n);
        for(auto edge: edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        dfs(graph,0, -1);
        vector<int> answer;
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0; j<27; j++)
        //         cout<<rootToNode[i][j]<<" ";
        //     cout<<endl;
        // }
        
        for(int i=1;i<LOG;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(par[i-1][j]==-1)
                    continue;
                par[i][j]= par[i-1][par[i-1][j]];
            }    
        }
        
        // for(int i=0;i<LOG;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<par[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(auto q: queries)
        {
            int u= q[0];
            int v= q[1];
            int lca= LCA(u,v);
            // cout<<lca<<endl;
            // int lca=0;
            
            vector<int> diff(27,0);
            for(int i=0;i<27;i++)
            {
                diff[i]= abs(rootToNode[u][i]- rootToNode[lca][i] + (rootToNode[v][i] - rootToNode[lca][i]));
            }
            
            int mxFreq=0;
            int sum=0;
            for(int i=0;i<27;i++)
            {
                sum+= diff[i];
                mxFreq= max(mxFreq, diff[i]);
            }
            
            answer.push_back(sum-mxFreq);
        }
        
        return answer;
    }
};
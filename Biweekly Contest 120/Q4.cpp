class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n= cost.size();
        vector<vector<int>> graph(n);
        for(auto edge: edges)
        {
            int u= edge[0]; int v= edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> cnt(n);
        vector<bool> visited(n,false);
        function< void(int) > cntNodes = [&](int src)
        {
            cnt[src]++;
            visited[src]= true;
            for(auto v: graph[src])
            {
                if(!visited[v])
                {
                    cntNodes(v);
                    cnt[src]+= cnt[v];
                }
            }
        };
        
        cntNodes(0);
        vector<long long> coins(n);
        
        for(int i=0; i<n; i++)
            visited[i]= false;
        
        
        
        function<pair<multiset<long long>, multiset<long long, greater<long long>>>(int)> dfs= [&](int src) -> pair<multiset<long long>, multiset<long long, greater<long long>>>
        {
            visited[src]= true;
            // cout<<src<<endl;
            multiset<long long> m1; // max elements
            multiset<long long, greater<long long>> m2; //min elements
            m1.insert(cost[src]);
            m2.insert(cost[src]);
            
            for(auto v: graph[src])
            {
                if(!visited[v])
                {
                    auto temp= dfs(v);
                    for(auto t: temp.first)
                        m1.insert(t);
                    
                    for(auto t: temp.second)
                        m2.insert(t);
                }
            }
            
            while(m1.size() > 3)
            {
                m1.erase(m1.begin());
            }
            
            while(m2.size() > 3)
            {
                m2.erase(m2.begin());
            }
            
            if(cnt[src]>= 3)
            {
                vector<long long> temp1, temp2;
                for(auto x: m1)
                    temp1.push_back(x);
                
                for(auto x: m2)
                    temp2.push_back(x);
                
                // cout<<temp1[0] <<" " <<temp1[1] <<" "<<temp1[2]<<endl;
                // cout<<temp2[0] <<" " <<temp2[1] <<" "<<temp2[2]<<endl;
                // cout<<temp1[0]* temp1[1]* temp1[2]<<endl;
                // cout<<temp2[0]* temp2[1]* temp1[2]<<endl;
                
                coins[src]= max({coins[src], temp1[0]* temp1[1]* temp1[2], temp1[2]* temp2[1]* temp2[2]});
            }
            else
            coins[src]=1;
            
            return {m1, m2};
        };
        
        dfs(0);
        return coins;
        
    }
};
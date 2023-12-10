class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        
        int totalSets= (1<<n);
        
        int ans=1;
        
        for(int i=1; i<totalSets; i++)
        {
            unordered_set<int> visited;
            for(int j=0; j<10; j++)
            {
                if(((1<<j)& i) == (1<<j))
                    visited.insert(j);
            }
            
            vector<vector<pair<int,int>>> graph(n);

            for(auto road: roads)
            {
                if(visited.count(road[0]) && visited.count(road[1]))
                {
                    graph[road[1]].push_back({road[2], road[0]});
                    graph[road[0]].push_back({road[2], road[1]});
                }
            }
            
            // for(auto g: graph)
            //     sort(g.begin(), g.end());
            
            
            int temp=0;
            for(auto x: visited)
            {
                vector<int> distTo(n, INT_MAX);
                priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
                

                pq.push({0, x});
                distTo[x]=0;
                while(!pq.empty())
                {
                    auto cur= pq.top();
                    pq.pop();
                    
                    for(auto y: graph[cur.second])
                    {
                        // cout<<y.first<<" "<<y.second<<endl;
                        if(y.first+ cur.first < distTo[y.second])
                        {
                            distTo[y.second]= y.first+ cur.first;
                            pq.push({distTo[y.second], y.second});
                        }
                        // cout<<distTo[y.second]<<endl;
                    }
                }
                
                // cout<< x << endl;
                // for(int j=0; j<n; j++)
                //     cout<< distTo[j] <<" ";
                // cout<<endl;
                
                for(auto x1: visited)
                    temp= max(temp, distTo[x1]);
            }
            
            // cout<< i<<" "<<temp<<endl;
            // for(auto x: visited)
            //     cout<<x<<" ";
            // cout<<endl;
            
            if(temp<=maxDistance)
                ans++;
        }
        
        return ans;
    }
};
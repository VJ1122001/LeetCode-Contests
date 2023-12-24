class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n= source.size();
        
        vector<vector<pair<int,int>>> graph(26);
        for(int i=0; i< original.size(); i++)
        {
            graph[original[i]-'a'].push_back({cost[i], changed[i]-'a'});
        }
        
        vector<vector<long long>> dist(26, vector<long long>(26, LONG_LONG_MAX));
        
        function<void(int)> getMinDistance= [&] (int src)
        {
            vector<long long> distTo(26, LONG_LONG_MAX);
            distTo[src]=0;
            
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, src});
            
            while(!pq.empty())
            {
                auto cur= pq.top();
                pq.pop();
                
                for(auto next: graph[cur.second])
                {
                    if(distTo[next.second] > distTo[cur.second]+ next.first)
                    {
                        distTo[next.second]= distTo[cur.second]+ next.first;
                        pq.push({distTo[next.second],next.second});
                    }
                }
            }
            
            dist[src]= distTo;
        };
        
        for(int i=0; i<26; i++)
            getMinDistance(i);
        
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            if(dist[source[i]-'a'][target[i]-'a']== LONG_LONG_MAX)
                return -1;
            else
                ans+= dist[source[i]-'a'][target[i]-'a'];
        }
        
        return ans;
    }
};
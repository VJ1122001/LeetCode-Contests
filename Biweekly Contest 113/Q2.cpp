class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> freq;
        
        for(auto num: nums)
            freq[num]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto x: freq)
            pq.push({x.second, x.first});
        
        while(!pq.empty())
        {
            auto mx1= pq.top();
            pq.pop();
            
            if(pq.empty())
                return mx1.first;
            
            auto mx2= pq.top();
            pq.pop();
            
            if(mx1.first-1>0) pq.push({mx1.first-1, mx1.second});
            
            if(mx2.first-1>0) pq.push({mx2.first-1, mx2.second});
        }
        
        return 0;
    }
};
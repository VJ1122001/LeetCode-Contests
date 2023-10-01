class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n= nums.size();
        
        long long ans=0;
        
        vector<long long> mxl(n,-1);
        vector<long long> mxr(n,-1);
        
        multiset<pair<int,int>> m;
        for(int j=0; j<n; j++)
        {
            auto it= m.rbegin();
            
            if(m.begin()== m.end())
            {
                m.insert({nums[j], j});
                continue;
            }
            
            mxl[j]= it->second;
            m.insert({nums[j], j});
        }
        
        m.clear();
        for(int j=n-1; j>=0; j--)
        {
            auto it= m.rbegin();
            
            if(m.begin()== m.end())
            {
                m.insert({nums[j], j});
                continue;
            }
            
            mxr[j]= it->second;
            m.insert({nums[j], j});
        }
        
        for(int j=0 ;j<n; j++)
        {
            if(mxl[j]>=0 && mxr[j]>=0)
            ans= max(ans, ((long long)nums[mxl[j]]- nums[j])* nums[mxr[j]]);
        }
        
        return ans;
        
    }
};
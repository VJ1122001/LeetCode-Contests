class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        int n= nums.size();
        
        vector<int> ans= {-1,-1};
        multiset<pair<int,int>> m;
        
        for(int i=n-1; i>=0; i--)
        {
            if(i+ indexDifference <=n-1)
                m.insert({nums[i+ indexDifference],i+indexDifference});
            
            if(m.empty())
                continue;
            
            int stIdx= m.begin()->second;
            int stEle= m.begin()->first;
            int enIdx= m.rbegin()->second;
            int enEle= m.rbegin()->first;
            
            if(abs(stEle - nums[i]) >= valueDifference)
            {
                ans= {stIdx, i};
                return ans;
            }
            
            if(abs(enEle - nums[i]) >= valueDifference)
            {
                ans= {enIdx, i};
                return ans;
            }
        }
        
        return ans;
        
    }
};
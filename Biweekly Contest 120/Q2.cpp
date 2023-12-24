class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> suffix(n);
        vector<long long> prefix(n);
        long long s=0;
        for(int i=n-1; i>=0; i--)
        {
            s+= nums[i];
            suffix[i]= s;
        }
        s=0;
        for(int i=0; i<n; i++)
        {
            s+= nums[i];
            prefix[i]= s;
        }
        
        
        long long ans=-1;
        for(int i=2; i<n; i++)
        {
            if(i-1 >=0)
            {
                if(prefix[i-1]> nums[i])
                    ans= max(prefix[i-1]+ (long long)nums[i], ans);
            }
            
        }
        
        return ans;
    }
};
class Solution {
public:
    long long mod= 1e9+7;
//     long long recur(vector<int>& nums, unordered_map<int,int>& lf, int i, int prevlf, vector<long long>& dp)
//     {
//         int n= nums.size();
//         if(i==n-1) return 1;
        
//         if(dp[i]!=-1)
//             return dp[i];
        
//         long long ans=0;
        
//         if(i== max(lf[nums[i]], prevlf))
//             ans+= recur(nums, lf, i+1, max(lf[nums[i]], prevlf), dp)% mod;
        
//         ans+= recur(nums, lf, i+1, max(lf[nums[i]], prevlf), dp)% mod;
        
//         return dp[i]= ans;
//     }
    int numberOfGoodPartitions(vector<int>& nums) {
        int n= nums.size();
        
        long long ans=1;
        
        unordered_map<int,int> lf;
        
        for(int i=0; i<n; i++)
        {
            lf[nums[i]]=i;
        }
        
        int prefixMax= 0;
        for(int i=0; i<n-1; i++)
        {
            prefixMax= max(lf[nums[i]], prefixMax);
            if(i==prefixMax)
            {
                ans*=2;
                ans%= mod;
            }
        }
        
        return ans % mod;
        // return recur(nums, lf, 0, lf[nums[0]], dp)% mod;
        
    }
};
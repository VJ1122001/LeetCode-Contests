class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        
        int n= nums.size();
        
        long long result=0;
        for(int i=1; i<=n; i++)
        {
            long long ans=0;
            for(int j=1; i*j*j<=n; j++)
            {
                ans+= nums[i*(j*j)-1];
                // cout<<i*j*j<<" ";
            }
            // cout<<endl;
            
            result= max(result,ans);
        }
        
        return result;
    }
};
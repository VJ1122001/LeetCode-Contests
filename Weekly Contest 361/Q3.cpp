class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        int n= nums.size();
        
        for(auto &num: nums) num= (num% modulo ==k)? 1: 0;
        
        vector<int> prefix(n,0);
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            prefix[i]= sum;
        }
        
        for(auto &p: prefix)
            p= p% modulo;
        
        long long ans=0;
        unordered_map<int,long long> freq;
        
        freq[0]=1;
        
        
        for(int i=0;i<n;i++)
        {
            ans+= freq[(prefix[i]-k + modulo)% modulo];
            freq[prefix[i]]++;
        }
        
        return ans;
        
    }
};
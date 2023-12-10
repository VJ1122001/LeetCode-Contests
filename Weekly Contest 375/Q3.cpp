class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        
        int mx= *max_element(nums.begin(), nums.end());
        
        int i=0;
        int j=0;
        long long ans=0;
        unordered_map<int,long long> freq;
        
        while(j<n)
        {
            // cout<< i<< " "<< j<<endl;
            while(j<n && freq[mx]< k)
            {
                freq[nums[j]]++;
                j++;
            }
            
            if(freq[mx] >=k)
            ans+= n-j+1;
            
            while(i<j && freq[mx] >=k)
            {
                freq[nums[i]]--;
                i++;
                
                if(freq[mx] >=k)
                    ans+= n-j+1;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        int i=0;
        int j=0;
        int res=0;
        
        unordered_map<int,int> freq;
        while(j<n)
        {
            freq[nums[j]]++;
            
            if(freq[nums[j]]> k)
            {
                while(i< j && freq[nums[j]] > k)
                {
                    freq[nums[i]]--;
                    i++;
                }
            }
            
            res= max(j-i+1, res);
            j++;
        }
        
        return res;
    }
};
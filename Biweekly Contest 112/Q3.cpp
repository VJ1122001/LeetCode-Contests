class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n= nums.size();
        
        long long sum=0;
        
        int j=0;
        unordered_map<int,int> unique;
        long long s=0;
        for(j=0;j<k-1;j++)
        {
            unique[nums[j]]++;
            s+= nums[j];
        }
        
        int i=0;
        
        while(j<n)
        {
            s+= nums[j];
            unique[nums[j]]++;
            
            if(unique.size() >= m)
            {
                // cout<<i<<" "<<j<<endl;
                sum= max(s, sum);
            }
            
            s-= nums[i];
            unique[nums[i]]--;
            if(unique[nums[i]]==0)
                unique.erase(nums[i]);
            i++;
            j++;
        }
        
        return sum;
    }
};
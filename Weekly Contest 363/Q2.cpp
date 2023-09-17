class Solution {
public:
    int countWays(vector<int>& nums) {
        
        int n= nums.size();
        sort(nums.begin(), nums.end());
        
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] < i+1 && nums[i+1]> i+1)
                count++;
        }
        
        if(nums[n-1] < n)
            count++;
        
        if(nums[0] > 0)
            count++;
        
        return count;
    }
};
class Solution {
public:
    unordered_map<int,bool> palindromes;
    bool isPalindromic(int n)
    {
        if(palindromes.count(n))
            return palindromes[n];
        
        int tempn= n;
        int rev= 0;
        while(n > 0)
        {
            rev*= 10;
            rev+= n%10;
            n/=10;
        }
        
        return palindromes[tempn]= rev== tempn;
    }
    
    long long cost(vector<int>& nums, int p)
    {
        int n= nums.size();
        long long cost=0;
        for(int i=0; i<nums.size(); i++)
            cost+= abs(nums[i]- p);
        
        return cost;
    }
    
    long long solve(int median, vector<int>& nums)
    {
        long long minCost= LONG_LONG_MAX;
        for(int i= median; i>=1; i--)
        {
            if(isPalindromic(i))
            {
                minCost= min(minCost, cost(nums, i));
                break;
            }
        }
        
        for(int i= median+1; i<1e9; i++)
        {
            if(isPalindromic(i))
            {
                minCost= min(minCost, cost(nums, i));
                break;
            }
        }
        
        return minCost;
    }
    
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        long long ans= LONG_LONG_MAX;
        
        if(n%2)
        {
            return ans= min(solve(nums[n/2], nums), ans);
        }
        
        if(n/2 >=0)
        {
            ans= min(solve(nums[n/2], nums), ans);
        }
        
        if(n/2-1 >=0)
        {
            ans= min(solve(nums[n/2-1], nums), ans);
        }
        
        if(n/2 >=0 && n/2-1 >=0)
        {
            ans= min(solve((nums[n/2]+ nums[n/2-1])/2, nums), ans);
        }
        
        return ans;
    }
};
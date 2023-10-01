class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        int n= nums.size();
        long long arrSum=0;
        
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
            arrSum+= nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        
        
        long long offset= (long long)target/ (6* arrSum);
        target%= (6* arrSum);
        // cout<<6* arrSum<<" "<< offset<<endl;
        
        int i=0;
        int j=0;
        int result= INT_MAX;
        long long sum=0;
        
        if(target==0) result=0;
        
        n= nums.size();
        
        while(target>0 && j<n)
        {
            // cout<<i<<" "<<j<<endl;
            while(j<n && sum< target)
            {
                sum+= nums[j];
                j++;
            }
            
            // cout<<i<<" "<<j<<endl;
    
            if(sum== target)
            result= min(result, j-i);
            
            while(i<j && sum>=target)
            {
                sum-= nums[i];
                i++;
                if(sum== target)
                    result= min(result, j-i);
            }
        }
        
        cout<<result<<endl;
        if(result== INT_MAX) return -1;
        
        return result + (n* offset);
    }
};
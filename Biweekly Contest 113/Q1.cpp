class Solution {
public:
    
    void rs(vector<int>& nums)
    {
        int n= nums.size();
        
        int t= nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            nums[i+1]= nums[i];
        }
        nums[0]= t;
    }
    
    int minimumRightShifts(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> temp;
        temp= nums;
        
        sort(temp.begin(), temp.end());
        if(temp== nums)
            return 0;
        
        // for(int i=0;i<n;i++)
        //     cout<<temp[i]<<" ";
        // cout<<endl;
        
        for(int i=0;i<n-1;i++)
        {
            rs(nums);
            // for(int i=0;i<n;i++)
            //     cout<<nums[i]<<" ";
            // cout<<endl;
            if(temp == nums)
                return i+1;
        }
        
        return -1;
        
    }
};
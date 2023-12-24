class Solution {
public:
    bool isValid(vector<int> nums, int i, int j)
    {
        int n= nums.size();
        
        vector<int> temp;
        for(int k=0; k<n; k++)
        {
            if(k>=i && k<=j)
                continue;
            else
                temp.push_back(nums[k]);
        }
        
        for(int k=1; k<temp.size(); k++)
        {
            if(temp[k] <= temp[k-1])
                return false;
        }
        
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(isValid(nums, i, j))
                {
                    // cout<<i <<" "<<j<<endl;
                    count++;
                }
            }
        }
        
        return count;
        
    }
};
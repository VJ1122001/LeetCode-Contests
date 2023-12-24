class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        
        vector<int> ans;
        for(int i=0; i<n; i+=2)
        {
            int a= nums[i];
            if(i+1 < n) 
            {
                int b= nums[i+1];
                ans.push_back(b);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};
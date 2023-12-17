class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n= nums.size();
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            int j= upper_bound(nums.begin()+i, nums.end(), nums[i]+k)- (nums.begin());
            
            int idx=-1;
            for(int _k= i; _k<j; _k++)
            {
                temp.push_back(nums[_k]);
                if(temp.size()==3)
                {
                    idx= _k;
                    break;
                }
            }
            
            // cout<<i <<" "<<j<<endl;
            if(idx==-1)
            {
                return {};
            }
            
            i= idx;
            ans.push_back(temp);
        }
        
        return ans;
    }
};
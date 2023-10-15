class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        
        int n= words.size();
        
        vector<int> nums;
        vector<int> ans;
        
        int j=-1;
        for(auto word: words)
        {
            if(word=="prev")
            {
                if(j==-1)
                    ans.push_back(-1);
                else
                {
                    ans.push_back(nums[j]);
                    j--;
                }
            }
            else
            {
                nums.push_back(stoi(word));
                j= nums.size()-1;
            }
        }
        
        return ans;
        
    }
};
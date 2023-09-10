class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        vector<int> prefix(102);
        
        for(auto num: nums)
        {
            prefix[num[0]]++;
            prefix[num[1]+1]--;
        }
        
        int sum=0;
        for(int i=0;i<102;i++)
        {
            sum+= prefix[i];
            prefix[i]= sum;
            
        }
        
        int count=0;
        for(int i=0;i<102;i++)
            if(prefix[i])
                count++;
        
        return count;
    }
};
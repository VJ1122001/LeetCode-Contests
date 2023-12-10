class Solution {
public:
    int countTestedDevices(vector<int>& bp) {
        
        int n= bp.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(bp[i] > 0)
            {
                count++;
                for(int j= i+1; j<n; j++)
                {
                    bp[j]= max(bp[j]-1, 0);
                }
            }
        }
        
        return count;
        
    }
};
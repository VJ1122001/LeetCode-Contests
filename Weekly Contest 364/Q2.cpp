class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        int n= maxHeights.size();
        
        long long result=0;
        for(int i=0;i<n;i++)
        {
            vector<int> temp= maxHeights;
            long long sum=0;
            int peak= maxHeights[i];
            for(int j=i-1; j>=0; j--)
            {
                if(temp[j] <= temp[j+1])
                    sum+= temp[j];
                else
                {
                    temp[j]= temp[j+1];
                    sum+= temp[j];
                }
            }
            
            for(int j=i+1; j<n; j++)
            {
                if(temp[j-1] >= temp[j])
                    sum+= temp[j];
                else
                {
                    temp[j]= temp[j-1];
                    sum+= temp[j];
                }
            }
            
            sum+=  peak;
            result= max(sum, result);
        }
        
        return result;
    }
};
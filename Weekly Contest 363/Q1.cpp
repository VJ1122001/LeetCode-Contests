class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        long long sum=0;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            int temp= i;
            int count=0;
            
            while(temp>0)
            {
                if(temp%2 ) count++;
                temp/=2;
            }
            
            if(count==k)
            {
                // cout<<temp<<endl;
                sum+= nums[i];
            }
        }
        
        return sum;
    }
};
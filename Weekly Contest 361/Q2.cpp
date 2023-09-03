int dp[101][25];
class Solution {
public:
    int recur(string num, int i, int rem)
    {
        int n= num.size();
        
        if(i==n && rem==0)
            return 0;
        if(i==n)
            return 1e9;
        
        if(dp[i][rem]!=-1) return dp[i][rem];
        
        int ans1= recur(num, i+1, (rem*10 + num[i]-'0')%25);
        int ans2= 1+ recur(num, i+1, rem);
        
        return dp[i][rem]= min(ans1,ans2);
    }
    
    int minimumOperations(string num) {
        
        memset(dp,-1, sizeof(dp));
        return recur(num,0, 0);
    }
};
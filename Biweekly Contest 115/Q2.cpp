class Solution {
public:
    
    vector<vector<int>> dp;
    int recur(vector<string>& words, vector<int>& groups, int prevGroup, int i, vector<bool>& taken)
    {
        int n= words.size();
        if(i==n) return 0;
        
        if(dp[i][prevGroup+1]!=-1) return dp[i][prevGroup+1];
        
        int ans1=0;
        int ans2=0;
        
        if(groups[i]!= prevGroup)
            ans1= 1+ recur(words, groups, groups[i], i+1, taken);
        
        ans2= recur(words, groups, prevGroup, i+1, taken);
        
        if(ans1 > ans2)
            taken[i]= true;
        
        return dp[i][prevGroup+1]= max(ans1, ans2);
        
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<bool> taken(n, false);
        dp.resize(n, vector<int>(n+1,-1));
        
        int len= recur(words, groups, -1, 0, taken);
        vector<string> ans;
        
        for(int i=0; i<n; i++)
        {
            if(taken[i])
                ans.push_back(words[i]);
        }
        
        
        return ans;
        
    }
};
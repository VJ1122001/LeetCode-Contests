class Solution {
public:
    int calculatehd(string& a, string& b)
    {
        if(a.size()!= b.size())
            return 0;
        
        int hd=0;
        
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]!=b[i])
            {
                hd++;
            }
        }
        
        return hd;
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n,1);
        
        vector<int> hash(n,1);
        for(int i=0; i<n;i++)
            hash[i]=i;
        
        vector<vector<int>> dist(n, vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<n; j++)
                dist[i][j]= calculatehd(words[i], words[j]);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(groups[j]!= groups[i] && dist[i][j]==1 && dp[i] < dp[j]+1)
                {
                    dp[i]= 1+ dp[j];
                    hash[i] = j;
                }
            }
        }
        
        // for(int i=0; i<n;i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        
        int ans = -1;
        int lastIndex =-1;

        for(int i=0; i<=n-1; i++)
        {
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<string> temp;
        temp.push_back(words[lastIndex]);

        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(words[lastIndex]);    
        }

        reverse(temp.begin(),temp.end());

        return temp;
        
    }
};
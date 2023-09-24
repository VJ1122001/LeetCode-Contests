class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n= maxHeights.size();
        
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && maxHeights[st.top()] >=  maxHeights[i])
                st.pop();
            
            if(!st.empty())
                pse[i]= st.top();
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && maxHeights[st.top()] >= maxHeights[i])
                st.pop();
            
            if(!st.empty())
                nse[i]= st.top();
            
            st.push(i);
        }
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<pse[i]<<" ";
//         }
//         cout<<endl;
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<nse[i]<<" ";
//         }
//         cout<<endl;
        
        vector<long long> prefixAns(n,0);
        vector<long long> suffixAns(n,0);
        
        for(int i=0; i<n;i++)
        {
            int prevSmallerIdx = pse[i];
            if(prevSmallerIdx == -1)
            {
                prefixAns[i]= (long long)maxHeights[i]* (i+1);
            }
            else
            {
                prefixAns[i]= (long long)maxHeights[i]* (i- prevSmallerIdx) + prefixAns[prevSmallerIdx]; 
            }
        }
        
        for(int i=n-1; i>=0; i--)
        {
            int nextSmallerIdx = nse[i];
            if(nextSmallerIdx == n)
            {
                suffixAns[i]= (long long)maxHeights[i]* (nextSmallerIdx- i);
            }
            else
            {
                suffixAns[i]= (long long)maxHeights[i]* (nextSmallerIdx - i) + suffixAns[nextSmallerIdx]; 
            }
        }
        
        long long result=0;
        for(int i=0;i<n;i++)
        {
            // cout<<prefixAns[i]<<" "<<suffixAns[i]<<endl;
            result= max(result, prefixAns[i]+ suffixAns[i]- maxHeights[i]);
        }
        
        return result;
        
    }
};
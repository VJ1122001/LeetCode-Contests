class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.size();
        
        int resLen= -1;
        string ans;
        
        for(int i=0; i<n;i++)
        {
            string temp;
            int c1=0;
            int c2=0;
            for(int j=i; j<n; j++)
            {
                temp.push_back(s[j]);
                if(s[j]=='1')
                    c1++;
                else
                    c2++;
                
                if(c1== k)
                {
                    int len= temp.size();
                    
                    if(ans.empty())
                    {
                        resLen= len;
                        ans= temp;
                    }
                    else
                    {
                        if(len < resLen)
                        {
                            resLen= len;
                            ans= temp;
                        }
                        else if(len == resLen)
                        {
                            ans= min(ans, temp);
                        }
                    }
                }
                
            }
        }
        
        return ans;
        
    }
};
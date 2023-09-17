class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        
        int n= coordinates.size();
        
        map<vector<int>,long long> freq;
        
        for(auto c: coordinates) freq[c]++;
        
        // cout<<INT_MAX<<endl;
        long long ans=0;
        
        for(auto c: coordinates)
        {
            for(int i=0;i<=k;i++)
            {
                int x= i;
                int y= k-i;
                
                if((x^c[0])==c[0] && (y^c[1])==c[1])
                {
                    ans+= (freq[c]-1);
                }
                else
                {
                    vector<int> key= {c[0]^x,c[1]^y};
                    if(freq.find(key)!= freq.end())
                        ans+= freq[{c[0]^x,c[1]^y}];
                    
                    // cout<<c[0]<<" "<<c[1]<<" "<<key[0]<<" "<<key[1]<<endl;
                }
            }
        }
        
        return ans/2;
    }
};
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n= s.size();
        int countOnes=0;
        for(auto c: s)
            if(c=='1')
                countOnes++;
        
        string ans;
        while(countOnes >1)
        {
            ans.push_back('1');
            countOnes--;
        }
            
        
        while(ans.size()<n-1)
            ans.push_back('0');
        ans.push_back('1');
        
        return ans;
    }
};
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        multiset<char> se1;
        multiset<char> se2;
        multiset<char> se3;
        multiset<char> se4;
        for(int i=0;i<4;i+=2)
            se1.insert(s1[i]);
        
        for(int i=1;i<4;i+=2)
            se2.insert(s1[i]);
        
        for(int i=0;i<4;i+=2)
            se3.insert(s2[i]);
        
        for(int i=1;i<4;i+=2)
            se4.insert(s2[i]);
        
    
        int i=0;
        for(auto c: se1)
        {
            s1[i]= c;
            i+=2;
        }
        
        i=1;
        for(auto c: se2)
        {
            s1[i]= c;
            i+=2;
        }
            
        
        i=0;
        for(auto c: se3)
        {
            s2[i]= c;
            i+=2;
        }
        
        i=1;
        for(auto c: se4)
        {
            s2[i]= c;
            i+=2;
        }
        
        return s1==s2;    
        
    }
};
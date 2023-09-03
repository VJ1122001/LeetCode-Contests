class Solution {
public:
    
    int countDigits(int n)
    {
        int count=0;
        while(n>0)
        {
            int d= n%10;
            n/=10;
            count++;
        }
        
        return count;
    }
    
    bool isSymmetric(int n)
    {
        if(countDigits(n)%2) return false;
        
        int d= countDigits(n);
        
        int k=0;
        int sum1=0;
        while(k< d/2)
        {
            sum1+= n%10;
            n/=10;
            k++;
        }
        
        int sum2= 0;
        while(k<d)
        {
            sum2+= n%10;
            n/=10;
            k++;
        }
        
        return sum1== sum2;
    }
    
    int countSymmetricIntegers(int low, int high) {
        
        int count=0;
        
        for(int i= low; i<=high; i++)
        {
            if(isSymmetric(i))
                count++;
        }
        
        return count;
        
    }
};
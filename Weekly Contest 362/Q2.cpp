class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx== fx && sy==fy && t!=1)
            return true;
        
        if(t==0)
        {
            if(sx!=fx)
                return false;
            if(sy!= fy)
                return false;
        }
        
        int diag=  min(abs(fx-sx), abs(fy-sy));
        
        int moves=diag;
        if(diag== abs(fx-sx))
            moves+=abs(fy-sy)- diag;
        else
            moves+= abs(fx-sx)- diag;
        
        // cout<<moves<<" "<<diag<<endl;
        if(moves <=t && moves>0)
            return true;
        else
            return false;
    }
};
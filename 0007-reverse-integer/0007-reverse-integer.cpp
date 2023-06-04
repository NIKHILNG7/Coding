class Solution {
public:
    int reverse(long long x) {
        
    //if(x<=9 && x>=0)return x;
        
        //if(x>-10 && x<0) return x;
        
        //if(x<INT_MIN)return 0;
        int value=0;
       long long digit=0;
        
        
        if(x<0){
            
            x=-x;
            value=-1;
            
        }
        else value=1;
        
        
        while (x>=1){
            
            
            digit=digit*10 + x%10;
            x=x/10;
            
            
        }
        
        long long k=value*digit;
        
        if(k<INT_MIN || k>INT_MAX)return 0;
        
        
        return k;
        
        
    }
};
class Solution {
public:
    int reverse(int x) {
        
       int digit=0;
    
        while (x){
            
             if(digit<INT_MIN/10 || digit>INT_MAX/10)return 0;
            else
            { digit=digit*10 + x%10;
            x=x/10;
            }   
        }   
       return int(digit);    
    }
};
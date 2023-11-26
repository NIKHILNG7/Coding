class Solution {
public:
    bool isPalindrome(string s) {
     
        string str;
        for(int i=0;i<s.length();i++){
            
            if(isalnum(s[i])){
                if(s[i]>=97)str+=s[i];
                
                else str += tolower(s[i]);
                
            }
            
        }
        
        bool statement=true;
        int j=0;
        int k=str.length();
        
        while(statement==true && j<(k/2) ){
            
            if(str[j]!=str[k-j-1]) statement=false;
                
                j++;
            
        }
        
        return statement;
        
    }
};
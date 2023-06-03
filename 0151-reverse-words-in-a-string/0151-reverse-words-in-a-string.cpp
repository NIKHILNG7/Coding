class Solution {
public:
    string reverseWords(string s) {
        
        int i=0;
        string ans="";
        
        
        
        int n=s.size();
        
        if(n==1 || n==0)return s;
        
        while(i<n){
            
            string temp="";
            
            while(s[i]==' ' && i<n){
                i++;
            }
            
            while(s[i]!=' '&& i<n){
                temp+=s[i];
                i++;
            }
            
            
            if(temp.size()>0){
                if(ans.size()==0)ans=temp;  // as we dont want space when we add first word
                else
                ans=temp+ " " + ans;        // if we add  our 1st word through this then we get space and ans=0 so conclusion we get temp word along with non reuquired space
                
                
            }
            
            
            
            
            
            
            
            
        }
        
        return ans;
        
        
    }
};
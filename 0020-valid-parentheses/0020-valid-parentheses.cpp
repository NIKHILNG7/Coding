class Solution {
public:
    bool isValid(string s) {
        
        stack<char>str;
        
        for(int i=0;i<s.length();i++){
            
            char temp=s[i];
           
            
            if(str.empty())str.push(temp); 
            
            else if ((temp==']' && str.top()=='[') || (temp=='}' && str.top()=='{') 
                    || (temp==')' && str.top() == '('))
            {
                str.pop();
                
            }
            
            else str.push(temp);
            
       
            
        }
      
        
        return str.empty();
        
    }
};
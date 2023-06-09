class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char ans;
        char tom={letters[0]};
        
  for(int i=0;i<letters.size();i++)      
        
  {
      
      
      if((letters[i]-'a')>(target-'a')){ans=letters[i];return ans;}
      
      
      
      
      
  }
        
        
        
        
        return tom;
    }
};
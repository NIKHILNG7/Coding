class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())return false;
        vector<int>dp(26,0);
        
        for(int i=0;i<s.length();i++){
            
            int pos=s[i]-'a';
            int pos2=t[i] -'a';
            dp[pos]++;
            dp[pos2]--;
            
        }
        
        for(int i=0;i<26;i++){
            
            if(dp[i])return false;
        }
        
        
        return true;
    }
};
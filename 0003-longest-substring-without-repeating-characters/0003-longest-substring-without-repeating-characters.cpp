class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0)return 0;
        
        if(s.length()==1)return 1;
        
        int arr[128]={0};
        int sum=0,sum2=INT_MIN;
        
        for(int i=0;i<s.length();i++){
            memset(arr, 0, sizeof(arr));
            //int k=s[i]-'a';
            
            //arr[k]++;
            
            int j=i;
            
           while((arr[s[j]])==0 && j<s.length()){
               sum++;
               arr[s[j]]++;
               j++;
           }
            
            sum2=max(sum,sum2);
            sum=0;
            //memset(arr, 0, sizeof(arr));
        }
        
        return sum2;
        
    }
};
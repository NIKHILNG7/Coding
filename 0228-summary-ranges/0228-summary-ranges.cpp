class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;   // use to store new unique string values 
         int n=nums.size();

  
        
        for(int i=0; i<n;i++){
            
            int start=nums[i];    // storing starting value of each range elements
            
            while(i<n-1 && nums[i]+1==nums[i+1]){
                
                i++;   //iterating till we find consecutive range elements
             }
               // checking whether the consective elements are same or not according to question Each range [a,b] in the list should be output as:"a" if a == b or  "a->b" if a != b
        
        
        if(start!=nums[i]){
            
         ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            
        }
        
        else   ans.push_back(to_string(start));
            
        }
         
       
    
        return ans;
    }
};
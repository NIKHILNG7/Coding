class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        
        unordered_map<int,int>mpp;
        
        for(int i=0;i<nums.size();i++){
            
            
            while(mpp.find(target-nums[i])!=mpp.end()){
                
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                
                return ans;
                
            }
            
            mpp[nums[i]]=i; // this will add num[i] value with respective index i 
            
        }
        
        return ans;       
        
        
    }
};
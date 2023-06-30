class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int s=nums.size();
        //int sum=0;
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<s;i++){
            
            //skipping i duplicates
            
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1;j<s;j++){
                
                //skipping j duplicates
                
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                
                int k=j+1;
                int l=s-1;
                
                while(k<l){
                    
                    long long sum=0;
                    sum+=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    
                    
                    if(sum==target){
                        
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        //sort(temp.begin(),temp.end());
                        ans.push_back(temp);
                        k++;l--;
                        
                    
                    
                    //skipping k duplicates
                        
                    while(k<l && nums[k]==nums[k-1]) k++;
                    //skipping l duplicates
                    
                 while(k<l && nums[l]==nums[l+1])l--;
                }
                    
                    else if(sum>target) l--;
                    
                    else k++;                   
                }
             }
             
        }
        return ans;
    }
};
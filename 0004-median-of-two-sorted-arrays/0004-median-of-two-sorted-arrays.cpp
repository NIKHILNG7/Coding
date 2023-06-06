class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        //stack<int>s;
        vector<double>s;
    
        int k=nums1.size() + nums2.size();
      
        int i=0,j=0;
        
    nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        
        
        while(s.size()<k){
            
            if(nums1[i]>nums2[j]){
                
                s.push_back(nums2[j]);
                j++;
                
            }
            
            else if(nums1[i]<nums2[j]){
                
                s.push_back(nums1[i]);
                i++;
                
            }
            
            if((nums1[i]==nums2[j])&&nums1[i]>=0){
                
                s.push_back(nums1[i]);
                s.push_back(nums2[j]);
                i++;
                j++;
                
            }
            
        }
        
       if((k%2)!=0) return s[k/2];
        else{
            
            return( (s[k/2] +s[(k/2)-1])/2  );
                   
                   }
        
        
        
        
    }
};
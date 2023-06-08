class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;
        
        for(int i=0;i<n;i++){
             int start=0;
                int last=m-1;
               while(start<=last){
                int mid=start+(last-start)/2;
                if(grid[i][mid]<0) last=mid-1;
                    
                    else start=mid+1;
                
                }
                
                sum+=m-start;
            }
            
            
            
        
        
        return sum;
    }
};
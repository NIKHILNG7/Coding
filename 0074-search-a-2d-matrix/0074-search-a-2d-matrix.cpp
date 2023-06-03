class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int m=matrix[0].size();
        int n=matrix.size();
        int final=0;
        
        for(int i=n-1;i>=0;i--){
            
            int k=matrix[i][m-1];
            
            if(k==target)return true;
            
            //if(target<=k && i==0){ final=0; break;}
            
            
            
            if(i!=0&&(target<k && target>matrix[i-1][m-1])){final=i;break;}    
            
            
            
        }
        
        for(int i=0;i<m;i++){
            
            if(matrix[final][i]==target) return true;
            
        }
        
        return false;
        
    }
};
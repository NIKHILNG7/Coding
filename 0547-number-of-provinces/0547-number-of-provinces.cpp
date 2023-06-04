class Solution {
    private: 
void dfs(vector<int>adj[],vector<int>&vis,int node){
    
    vis[node]=1;
    
    for(auto it : adj[node]){
        
        if(!vis[it]){
            
            dfs(adj,vis,it);
        }
        
    }
    
    
    
}
    
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        int m=isConnected[0].size();
        
       
        
        vector<int>adj[n];
        
        //converting matrix into adjaceny list for our ease
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(isConnected[i][j]==1 && i!=j) {
                    
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    
                } 
                
            }
            }
        
           vector<int>vis(n,0);
            int count=0;
            
            
            for(int i=0;i<n;i++){
                
                if(!vis[i]){
                    
                    count++;
                    dfs(adj,vis,i);
                }
                
            }
            
return count;
            
        }
        
        
        
        
        
        
        
    
};
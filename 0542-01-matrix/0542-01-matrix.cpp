class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
                                
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(mat[row][col]==0) {
                    vis[row][col]=1;
                    q.push({{row,col},0});
                }
                else vis[row][col]=0;
            }
        }
        
        int delrow[]={0,+1,0,-1};
        int delcol[]={+1,0,-1,0};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            
            dist[row][col]=steps;
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        
        return dist;
    }                        
};

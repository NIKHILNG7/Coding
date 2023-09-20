class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
int ncol=grid.size();
int nrow=grid[0].size();        

vector<vector<int>>dp(ncol,vector<int>(nrow));

dp[0][0]=grid[0][0];

for(int i=1;i<nrow;i++){

dp[0][i]=grid[0][i] + dp[0][i-1];

}

for(int i=1;i<ncol;i++){

dp[i][0]=grid[i][0] + dp[i-1][0];

}

for(int i=1;i<ncol;i++){

for(int j=1;j<nrow;j++){

int mini=min((dp[i][j-1]),(dp[i-1][j]));
dp[i][j]=grid[i][j] + mini;

}

}

return dp[ncol-1][nrow-1];


    }
};
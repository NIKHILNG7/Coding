 class Solution {    int dp[21][10003];
    int result = 0;
public:
    int calculateTallestBillboard(int i, int sum, vector<int>& rods){
        if(i >= rods.size()) return sum == 0 ? 0 : -1; 
        if(dp[i][sum + 5000]) return dp[i][sum + 5000];
        int x = calculateTallestBillboard(i + 1, sum + rods[i], rods);
        x = x == -1 ? -1 : x + rods[i];
        int y = calculateTallestBillboard(i + 1, sum - rods[i], rods);
        int z = calculateTallestBillboard(i + 1, sum, rods);
        return dp[i][sum + 5000] = max({x, y, z});
    }
    
    int tallestBillboard(vector<int>& rods) {
        memset(dp, 0, sizeof(dp));
        int result = calculateTallestBillboard(0, 0, rods);
        return result == -1 ? -1 : result;
    }
};

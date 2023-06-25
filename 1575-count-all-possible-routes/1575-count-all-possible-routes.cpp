class Solution {
    int MOD = 1e9 + 7;
    int helper(vector<int>& locations, int currCity, int finishCity, int remainingFuel, vector<vector<int>>& dp) {
        if (remainingFuel < 0) {
            return 0;
        }
        if (dp[currCity][remainingFuel] != -1) {
            return dp[currCity][remainingFuel];
        }

        int ans = currCity == finishCity ? 1 : 0;
        for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
            if (nextCity != currCity) {
                ans = (ans + helper(locations, nextCity, finishCity, remainingFuel - abs(locations[currCity] - locations[nextCity]), dp)) % MOD;
            }
        }

        return dp[currCity][remainingFuel] = ans;
    }
public:
    int countRoutes(vector<int>& locations, int startCity, int finishCity, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));

        return helper(locations, startCity, finishCity, fuel, dp);
        
    }
};
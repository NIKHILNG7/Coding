class Solution {

    public:
    int solve(int i, int j, int& size1, int& size2, int prev, vector<vector<int>>& dp, vector<int>& arr1, vector<int>& arr2) {
        if (i == size1) {
            return 0;
        }
        j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (j == size2 && arr1[i] <= prev) {
            return 2001;
        }
        int take = 2001, nottake = 2001;
        if (j != size2) {
            take = solve(i + 1, j + 1, size1, size2, arr2[j], dp, arr1, arr2) + 1;
        }
        if (arr1[i] > prev) {
            nottake = solve(i + 1, j, size1, size2, arr1[i], dp, arr1, arr2);
        }
        return dp[i][j] = min(take, nottake);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int size1 = arr1.size();
        int size2 = arr2.size();
        vector<vector<int>> dp(2001, vector<int>(2001, -1));
        sort(arr2.begin(), arr2.end());
        int result = solve(0, 0, size1, size2, -1, dp, arr1, arr2);
        if (result > size1) {
            return -1;
        }
        return result;
    }
};
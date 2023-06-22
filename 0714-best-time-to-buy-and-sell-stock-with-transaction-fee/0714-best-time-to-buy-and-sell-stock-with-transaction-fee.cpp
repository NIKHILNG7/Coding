class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cash(n, 0), stock(n, 0);
        
        // In order to hold a stock on day 0, we have no other choice but to buy it for prices[0].
        stock[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            cash[i] = max(cash[i - 1], stock[i - 1] + prices[i] - fee);
            stock[i] = max(stock[i - 1], cash[i - 1] - prices[i]);
        }
        
        return cash[n - 1];
    }
};
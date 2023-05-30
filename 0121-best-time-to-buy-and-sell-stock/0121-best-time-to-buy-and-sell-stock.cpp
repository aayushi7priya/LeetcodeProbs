class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0; // No profit can be made
        }
        
        vector<int> dp(n, 0);
        int min_stock = prices[0]; 
        
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1], prices[i] - min_stock); 
            min_stock = min(min_stock, prices[i]); 
        }
        
        return dp[n-1]; // Return the maximum profit
    }
};

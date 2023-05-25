class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_stock = 1e9;
        for(int i =0;i<n;i++)
        {
            min_stock = min(min_stock, prices[i]);
            max_profit = max(max_profit, prices[i]-min_stock);
        }
        
        return max_profit;
    }
};
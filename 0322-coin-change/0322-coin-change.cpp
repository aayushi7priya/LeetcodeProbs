class Solution {
public:
    int dp[10002];
    int rec(int amount, vector<int>& coins) {
        
        int n = coins.size();
        if (amount == 0)
            return dp[0] = 0;
        
        if (amount < 0)
            return -1;
        
        if(dp[amount]!=-1)
            return dp[amount];
        
        int ans = INT_MAX-1;
        for (int i = 0; i < n; i++) {
            if (amount - coins[i] >= 0) {
                //this subproblem to check if sum is not possible in that case
                int subproblem = rec(amount - coins[i], coins);
                if (subproblem != -1)
                    ans = min(ans, 1 + subproblem);
            }
        }
        dp[amount] = ans;
        
        return (ans == INT_MAX-1) ? -1 : ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1,sizeof(dp));
        return rec(amount, coins); 
    }
};

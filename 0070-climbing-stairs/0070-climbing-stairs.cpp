class Solution {
public:
    int dp[46];
    
    Solution() {
        memset(dp, -1, sizeof(dp)); // Initialize dp array to -1
    }
    
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        return (dp[n] = climbStairs(n - 1) + climbStairs(n - 2));
    }
};

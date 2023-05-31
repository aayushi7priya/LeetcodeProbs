class Solution {
public:
    int dp[10002];
    Solution()
    {
        memset(dp, -1,sizeof(dp));
    }
    bool isPerfectSquare(int num) {
        int sqrtNum = sqrt(num);
        return sqrtNum * sqrtNum == num;
    }
    
    int numSquares(int n) {
        // Base case: if n is a perfect square, return 1
        if (isPerfectSquare(n))
            return dp[n] = 1;
        
        if(dp[n]!=-1)return dp[n];
        int ans = INT_MAX;  
        
        for (int i = 1; i * i <= n; i++) {
            ans = min(ans, 1 + numSquares(n - i * i));
        }
        
        return dp[n] = ans;
    }
};

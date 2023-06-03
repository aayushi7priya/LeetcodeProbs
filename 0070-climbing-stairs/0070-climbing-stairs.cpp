class Solution {
public:
    int n;
    int dp[50];
    int rec(int i)
    {
        if(i>n)
            return 0;
        if(i==n)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int ans = 0;
        ans = rec(i+1) + rec(i+2);
        
        return dp[i] = ans;
    }
    int climbStairs(int t) {
        memset(dp,-1, sizeof(dp));
        n = t;
       return  rec(0);
    }
};
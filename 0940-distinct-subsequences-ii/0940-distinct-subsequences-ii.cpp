class Solution {
public:
    int n;
    int dp[2002], sum[2002], last[2002];
    const int MOD = 1000000007;

    int distinctSubseqII(string s) {
        memset(last, 0, sizeof(last));
        n = s.size(); 
        dp[0] = 1;
        sum[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = sum[i - 1] % MOD;
            if (last[s[i - 1]] > 0)
                dp[i] = (dp[i] - sum[last[s[i - 1]] - 1] + MOD) % MOD;
            last[s[i - 1]] = i;
            sum[i] = (dp[i] + sum[i - 1]) % MOD;
        }
        return (sum[n] - 1 + MOD) % MOD;
    }
};

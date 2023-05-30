class Solution {
public:
    int dp[101];
    
    int rec(int i, string &s) {
        int n = s.size();
        if (i >= n - 1)
            return s[i] != '0' ? 1 : 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans = 0;
        if (s[i] != '0')
            ans = rec(i + 1, s);
        
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
            ans += rec(i + 2, s);
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(0, s);
    }
};
